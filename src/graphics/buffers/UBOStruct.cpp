//
// Created by lejonmcgowan on 7/2/16.
//

#include <iostream>
#include "UBOStruct.h"

using namespace std;

UBOStruct::UBOStruct(std::string name) : UBOData(name)
{

}

void UBOStruct::AddData(std::shared_ptr<UBOData> data)
{
    //make sure that we aren't re-counting offsets for exsisting entries
    if (dataMap.find(data->name) == dataMap.end())
    {
        data->offset = totalSize;
        totalSize += data->calcTotalSize();
    }
    dataMap[name] = data;
}

UBOPrimitive &UBOStruct::getUniform(std::string name)
{
    assert(dataMap.find(name) != dataMap.end());
    assert(dataMap[name]->getType() == "primitive");
    return (UBOPrimitive &) (*dataMap[name]);
}

UBOPrimitiveArray &UBOStruct::getUniformArray(std::string name)
{
    assert(dataMap.find(name) != dataMap.end());
    assert(dataMap[name]->getType() == "primitive array");
    return (UBOPrimitiveArray &) (*dataMap[name]);
}

UBOStruct &UBOStruct::getUniformStruct(std::string name)
{
    assert(dataMap.find(name) != dataMap.end());
    assert(dataMap[name]->getType() == "struct");
    return (UBOStruct &) (*dataMap[name]);
}

UBOStructArray &UBOStruct::getUniformStructArray(std::string name)
{
    assert(dataMap.find(name) != dataMap.end());
    assert(dataMap[name]->getType() == "struct array");
    return (UBOStructArray &) (*dataMap[name]);
}

int UBOStruct::calcTotalSize()
{
    int finalSize = totalSize;
    //round finalSize up to the nearest vec4 value
    finalSize += finalSize % 16;
    return finalSize;
}

void UBOStruct::update(int currentOffset)
{
    for (auto entry: dataMap)
        entry.second->update(currentOffset);
}

std::string UBOStruct::getType()
{
    return "struct";
}

void UBOStruct::operator=(const UBOStruct &otherStruct)
{
    dirty = otherStruct.dirty;
    offset = otherStruct.offset;
    totalSize = otherStruct.totalSize;
    for (auto entry: otherStruct.dataMap)
        dataMap.emplace(entry);
}


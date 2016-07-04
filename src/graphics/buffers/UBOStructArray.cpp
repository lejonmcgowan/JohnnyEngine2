//
// Created by lejonmcgowan on 7/2/16.
//

#include "UBOStructArray.h"

UBOStructArray::UBOStructArray(std::string name, const std::string structName, int size) : UBOData(name),
                                                                                           numElements(size),
                                                                                           structName(structName)
{
    UBOStructList.reserve(size);
    for (int i = 0; i < size; i++)
        inits.push_back(false);
}

void UBOStructArray::setStruct(UBOStruct &ubostruct, int position)
{
    assert(position >= 0 && position < numElements);
    assert(ubostruct.name == structName);
    UBOStructList[position] = ubostruct;
    ubostruct.offset = offset + ubostruct.calcTotalSize() * position;
    inits[position] = true;
}

UBOStruct &UBOStructArray::getStruct(int position)
{
    if (!inits[position])
        std::cout << "Warning. position " << position << " not initialized" << std::endl;

    return UBOStructList[position];
}

int UBOStructArray::calcTotalSize()
{
    assert(inits[0]);
    return numElements * UBOStructList[0].calcTotalSize();
}

void UBOStructArray::update(int currentOffset)
{
    for (int i = 0; i < numElements; i++)
    {
        if (inits[i])
            UBOStructList[i].update(currentOffset);
    }

}

std::string UBOStructArray::getType()
{
    return "struct array";
}
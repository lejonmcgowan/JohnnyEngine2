//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UBOSTRUCT_H
#define OGLSIMPLEENGINE_UBOSTRUCT_H

#include <glm/glm.hpp>
#include <map>
#include <memory>
#include "UBOData.h"
#include "UBOPrimitive.h"
#include "UBOPrimitiveArray.h"

class UBOStructArray;

class UBOStruct : public UBOData
{
private:
    friend class UBOStructArray;

    std::map<std::string, std::shared_ptr<UBOData>> dataMap;
    int totalSize;
public:
    UBOStruct(std::string name);

    void AddData(std::shared_ptr<UBOData> data);

    UBOPrimitive &getUniform(std::string name);

    UBOPrimitiveArray &getUniformArray(std::string name);

    UBOStruct &getUniformStruct(std::string name);

    UBOStructArray &getUniformStructArray(std::string name);

    virtual int calcTotalSize();

    virtual void update(int currentOffset);

    virtual std::string getType();

    void operator=(const UBOStruct &otherStruct);

};


#endif //OGLSIMPLEENGINE_UBOSTRUCT_H

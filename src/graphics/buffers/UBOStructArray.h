//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UBOSTRUCTARRAY_H
#define OGLSIMPLEENGINE_UBOSTRUCTARRAY_H


#include <vector>
#include <iostream>
#include "UBOData.h"
#include "UBOStruct.h"

class UBOStructArray : public UBOData
{
private:
    const int numElements;
    std::vector<UBOStruct> UBOStructList;
    std::vector<bool> inits;
    std::string structName;
public:
    UBOStructArray(std::string name, const std::string structName, int size);

    void setStruct(UBOStruct &ubostruct, int position);

    UBOStruct &getStruct(int position);

    virtual int calcTotalSize() override;

    virtual void update(int currentOffset) override;

    virtual std::string getType() override;
};


#endif //OGLSIMPLEENGINE_UBOSTRUCTARRAY_H

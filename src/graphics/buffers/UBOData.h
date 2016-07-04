//
// Created by lejonmcgowan on 7/2/16.
//

#ifndef OGLSIMPLEENGINE_UBODATA_H
#define OGLSIMPLEENGINE_UBODATA_H


#include <string>
#include "UniformData.h"

class UBOData
{
private:
    friend class UBOStruct;

protected:
    int offset;
    bool dirty = true;
public:
    const std::string name;

    UBOData(std::string name) : name(name)
    { }

    virtual int calcTotalSize() = 0;

    virtual void update(int currentOffset) = 0;

    bool isDirty()
    { return dirty; }

    virtual std::string getType() = 0;
};


#endif //OGLSIMPLEENGINE_UBODATA_H

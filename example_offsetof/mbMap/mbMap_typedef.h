
#ifndef MBMAP_TYPEDEF_H_
#define MBMAP_TYPEDEF_H_

#include <stdint.h>

typedef enum
{
    eThermistorCoeff,
    eProbeCoeff,
    eFirmwareInfo,
    eMeasurement,
    eProductInfo,
    eStatus,
    eTiming,

    eMaxDataObj
}DataObj_enum;

typedef struct
{
    DataObj_enum data_obj;
    void* pDataStruct;
}mbObjMap_st;

typedef struct
{
    uint16_t reg_address;
    uint8_t struct_size;
    DataObj_enum data_obj;

}mbMap_st;

typedef struct
{
    DataObj_enum data_obj;
    uint8_t offset;

}mbMemberMap_st;

#endif /* MBMAP_TYPEDEF_H_ */

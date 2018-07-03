
#ifndef MBMAP_TYPEDEF_H_
#define MBMAP_TYPEDEF_H_

#include <stdint.h>
#include "mbData_typedef.h"

typedef struct
{
    uint16_t reg_address;
    uint8_t struct_size;
    void* pDataStruct;
}mbMap_st;

extern CoeffT* Coeff_getObj(uint16_t reg_address);
extern FirmwareInfoT* FirmwareInfo_getObj(uint16_t reg_address);
extern MeasurementT* Measurement_getObj(uint16_t reg_address);
extern ProductInfoT* ProductInfo_getObj(uint16_t reg_address);
extern StatusT* Status_getObj(uint16_t reg_address);
extern TimingT* Timing_getObj(uint16_t reg_address);


#endif /* MBMAP_TYPEDEF_H_ */

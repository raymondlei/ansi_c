
#ifndef MB_MAPPER_H_
#define MB_MAPPER_H_

#include "modbus_datatypes.h"

typedef struct
{
    uint16_t reg_address;
    uint8_t struct_size;
    void* pDataStruct;
}mbMap_st;

extern CoeffT tankThermister, probe;
extern FirmwareInfoT firmwareInfo;
extern MeasurementT measurement;
extern ProductInfoT dispenser;
extern StatusT appStatus;
extern TimingT appUpTime;


extern const mbMap_st mbMap[];
extern const uint16_t mbMap_size;


extern void* mbMap_getObj(const mbMap_st* p_map, uint16_t index);
extern uint16_t mbMap_getRegAddress(const mbMap_st* p_map, uint16_t index);
extern uint16_t mbMap_getStructSize(const mbMap_st* p_map, uint16_t index);
extern uint16_t mbMap_lookup(uint16_t reg_address);


extern CoeffT* Coeff_getObj(const mbMap_st* p_map, uint16_t reg_address);

#endif /* MB_MAPPER_H_ */

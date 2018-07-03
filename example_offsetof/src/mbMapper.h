
#ifndef MB_MAPPER_H_
#define MB_MAPPER_H_

#include <stdint.h>
#include "mbMap_typedef.h"
#include "mbData_typedef.h"

extern CoeffT tankThermisterCoeff, probeCoeff;
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
extern uint16_t mbMap_lookup(const mbMap_st* p_map, uint16_t map_size, uint16_t reg_address);

#endif /* MB_MAPPER_H_ */

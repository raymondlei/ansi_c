
#ifndef MB_MAPPER_H_
#define MB_MAPPER_H_

#include <stdint.h>
#include "mbMap_typedef.h"

extern void* mbMap_getObj(const mbObjMap_st* p_map, uint16_t index);

extern uint16_t mbMap_getStructSize(const mbMap_st* p_map, uint16_t index);
extern uint16_t mbMap_getRegAddress(const mbMap_st* p_map, uint16_t index);
extern DataObj_enum mbMap_lookupDataType(const mbMap_st* p_map, uint16_t map_size, uint16_t reg_address);

extern uint16_t mbMap_lookupObj(const mbObjMap_st* pObj_map, uint16_t map_size, DataObj_enum key);

#endif /* MB_MAPPER_H_ */

#include <stdint.h>

#include "modbus_datatypes.h"
#include "mbMapper.h"


static inline uint16_t _lookup(uint16_t reg_address);


void* mbMap_getObj(const mbMap_st* p_map, uint16_t index)
{
    return (p_map + index)->pDataStruct;
}

uint16_t mbMap_getRegAddress(const mbMap_st* p_map, uint16_t index)
{
    return (p_map + index)->reg_address;
}

uint16_t mbMap_getStructSize(const mbMap_st* p_map, uint16_t index)
{
    return (p_map + index)->struct_size;
}


uint16_t mbMap_lookup(uint16_t reg_address)
{
    return _lookup(reg_address);
}


CoeffT* Coeff_getObj(const mbMap_st* p_map, uint16_t reg_address)
{
    uint16_t idx = _lookup(reg_address);

    return (CoeffT*) (p_map + idx)->pDataStruct;
}

static inline uint16_t _lookup(uint16_t reg_address)
{
    uint16_t idx;

    for(idx = 0; idx < mbMap_size; idx++)
    {
        if(mbMap[idx].reg_address == reg_address)
            break;

        if((mbMap[idx].reg_address < reg_address) && (reg_address <= (mbMap[idx].reg_address + mbMap[idx].struct_size)))
        {
            break;
        }
    }

    return idx;
}

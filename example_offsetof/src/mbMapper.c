#include <stdint.h>

#include "mbMap_typedef.h"
#include "mbMapper.h"

/*
 * -----------------------------------------------------------------------------
 * Public functions implementation
 * -----------------------------------------------------------------------------
 */
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

uint16_t mbMap_lookup(const mbMap_st* p_map, uint16_t map_size, uint16_t reg_address)
{
    uint16_t idx;

    for(idx = 0; idx < map_size; idx++)
    {
        if((p_map + idx)->reg_address == reg_address)
            break;

        if(((p_map + idx)->reg_address < reg_address) &&
            (((p_map + idx)->reg_address +
              (p_map + idx)->struct_size)) >= reg_address)
        {
            break;
        }
    }

    return idx;
}

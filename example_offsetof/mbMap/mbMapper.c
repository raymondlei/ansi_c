#include <stdint.h>

#include "mbMap_typedef.h"

/*
 * -----------------------------------------------------------------------------
 * Public functions implementation
 * -----------------------------------------------------------------------------
 */
void* mbMap_getObj(const mbObjMap_st* p_map, uint16_t index)
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

DataObj_enum mbMap_lookupDataType(const mbMap_st* p_map, uint16_t map_size, uint16_t reg_address)
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

    return (p_map + idx)->data_obj;
}

uint16_t mbMap_lookupBaseAddress(const mbMap_st* p_map, uint16_t map_size, DataObj_enum data_type)
{
    uint16_t idx;

    for(idx = 0; idx < map_size; idx++)
    {
        if((p_map + idx)->data_obj == data_type)
            break;
    }

    if(idx < map_size)
        return (p_map + idx)->reg_address;
    else
        return 0;
}

uint16_t mbMap_lookupObj(const mbObjMap_st* pObj_map, uint16_t map_size, DataObj_enum key)
{
    uint16_t idx;

    for(idx = 0; idx < map_size; idx++)
    {
        if((pObj_map + idx)->data_obj == key)
        {
            break;
        }
    }

    return idx;
}

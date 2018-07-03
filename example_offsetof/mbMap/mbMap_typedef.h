
#ifndef MBMAP_TYPEDEF_H_
#define MBMAP_TYPEDEF_H_

#include <stdint.h>

typedef struct
{
    uint16_t reg_address;
    uint8_t struct_size;
    void* pDataStruct;
}mbMap_st;

#endif /* MBMAP_TYPEDEF_H_ */

/*
 *
 *
 * Test cases:
 * 1. Read/Write individual modbus register
 * 2. Read/Write un-assigned modbus register
 * 3. Read/Write an entire struct
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "mbMap_typedef.h"
#include "mbData_typedef.h"
#include "mbMapper.h"

static inline void _writeStruct_CoeffT(CoeffT* p_obj)
{
    if(p_obj != NULL)
    {
        p_obj->coeffA = 1.1;
        p_obj->coeffB = 2.2;
        p_obj->coeffC = 3.3;
    }
}

static inline void DisplayCoeff(CoeffT* p_obj)
{
    printf("Data = %f\n", p_obj->coeffA);
    printf("Data = %f\n", p_obj->coeffB);
    printf("Data = %f\n", p_obj->coeffC);
}

int main(void)
{
    const mbMap_st* pMap = mbMap_getHandle();
    uint16_t size = mbMap_getSize();

    CoeffT* pObj;
    uint16_t index = 0;
    DataObj_enum data_type;

    mbMap_showMember();

    pObj = Coeff_getObj(0x1243);
    DisplayCoeff(pObj);

    _writeStruct_CoeffT(pObj);

    pObj = Coeff_getObj(0x1240);
    DisplayCoeff(pObj);


//    data_type = mbMap_lookupDataType(pMap, size, 0x1243);
//    pObj = (CoeffT*) mbMap_getObj(pMap, index);
//    DisplayCoeff(pObj);
//
//    pObj = Coeff_getObj(0x1200);
//    DisplayCoeff(pObj);


//    ShowCoeffT();
//    ShowFirmwareInfoT();

	return EXIT_SUCCESS;
}

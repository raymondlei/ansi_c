
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

static inline void TraverseMap(void)
{
    const mbMap_st* pMap = &mbMap[0];
    uint8_t idx = 0;

    for(idx = 0; idx < mbMap_size; idx++)
    {
        printf("Reg Address = 0x%x\n", mbMap_getRegAddress(pMap, idx));
    }
}


int main(void)
{
    const mbMap_st* pMap = &mbMap[0];
    CoeffT* pObj;
    uint16_t index;

    TraverseMap();

    pObj = Coeff_getObj(0x1240);
    DisplayCoeff(pObj);

    _writeStruct_CoeffT(pObj);

    pObj = Coeff_getObj(0x1243);
    DisplayCoeff(pObj);

    index = mbMap_lookup(pMap, mbMap_size, 0x1243);
    pObj = (CoeffT*) mbMap_getObj(pMap, index);
    DisplayCoeff(pObj);

    pObj = Coeff_getObj(0x1200);
    DisplayCoeff(pObj);


//    ShowCoeffT();
//    ShowFirmwareInfoT();

	return EXIT_SUCCESS;
}

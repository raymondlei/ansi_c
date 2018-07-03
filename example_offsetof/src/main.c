/*
 ============================================================================
 Name        : example_offsetof.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "modbus_datatypes.h"
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
    CoeffT* pObj;

    pObj = Coeff_getObj(0x1240);
    DisplayCoeff(pObj);

    _writeStruct_CoeffT(pObj);

    pObj = Coeff_getObj(0x1240);
    DisplayCoeff(pObj);

    pObj = Coeff_getObj(0x1200);
    DisplayCoeff(pObj);

//    ShowCoeffT();
//    ShowFirmwareInfoT();

	return EXIT_SUCCESS;
}

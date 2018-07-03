#include <stdint.h>

#include "modbus_datatypes.h"
#include "mbMapper.h"


CoeffT tankThermister, probe;
FirmwareInfoT firmwareInfo;
MeasurementT measurement;
ProductInfoT dispenser;
StatusT appStatus;
TimingT appUpTime;

static inline uint16_t _lookup(uint16_t reg_address);


CoeffT* Coeff_getObj(uint16_t reg_address)
{
    uint16_t idx = _lookup(reg_address);

    return (CoeffT*) mbMap[idx].pDataStruct;
}




static inline uint16_t _lookup(uint16_t reg_address)
{
    uint16_t idx;

    for(idx = 0; idx < mbMap_size; idx++)
    {
        if(mbMap[idx].reg_address == reg_address)
            break;
    }

    return idx;
}

#include <stdint.h>

#include "mbData_typedef.h"
#include "mbMapper.h"

CoeffT tankThermisterCoeff, probeCoeff;
FirmwareInfoT firmwareInfo;
MeasurementT measurement;
ProductInfoT dispenser;
StatusT appStatus;
TimingT appUpTime;

const mbMap_st mbMap[] =
{
    {0x1200, sizeof(CoeffT), (void*)&tankThermisterCoeff},
    {0x1240, sizeof(CoeffT), (void*)&probeCoeff},

    {0x1280, sizeof(FirmwareInfoT), (void*)&firmwareInfo},

    {0x12C0, sizeof(MeasurementT), (void*)&measurement},

    {0x1300, sizeof(ProductInfoT), (void*)&dispenser},

    {0x1340, sizeof(StatusT), (void*)&appStatus},

    {0x1380, sizeof(TimingT), (void*)&appUpTime}
};

const uint16_t mbMap_size = sizeof(mbMap) / sizeof(mbMap_st);

static inline void* _getObj(uint16_t reg_address);

/*
 * -----------------------------------------------------------------------------
 * Public functions implementation
 * -----------------------------------------------------------------------------
 */
CoeffT* Coeff_getObj(uint16_t reg_address)
{
    return (CoeffT*) _getObj(reg_address);
}

FirmwareInfoT* FirmwareInfo_getObj(uint16_t reg_address)
{
    return (FirmwareInfoT*) _getObj(reg_address);
}

MeasurementT* Measurement_getObj(uint16_t reg_address)
{
    return (MeasurementT*) _getObj(reg_address);
}

ProductInfoT* ProductInfo_getObj(uint16_t reg_address)
{
    return (ProductInfoT*) _getObj(reg_address);
}

StatusT* Status_getObj(uint16_t reg_address)
{
    return (StatusT*) _getObj(reg_address);
}

TimingT* Timing_getObj(uint16_t reg_address)
{
    return (TimingT*) _getObj(reg_address);
}

/*
 * -----------------------------------------------------------------------------
 * Private functions implementation
 * -----------------------------------------------------------------------------
 */
static inline void* _getObj(uint16_t reg_address)
{
    uint16_t idx = mbMap_lookup(&mbMap[0], mbMap_size, reg_address);
    return mbMap_getObj(&mbMap[0], idx);
}

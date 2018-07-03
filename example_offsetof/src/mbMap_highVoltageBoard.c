
#include "mbMapper.h"


CoeffT tankThermister, probe;
FirmwareInfoT firmwareInfo;
MeasurementT measurement;
ProductInfoT dispenser;
StatusT appStatus;
TimingT appUpTime;


const mbMap_st mbMap[] =
{
    {0x1200, sizeof(CoeffT), (void*)&tankThermister},
    {0x1240, sizeof(CoeffT), (void*)&probe},

    {0x1280, sizeof(FirmwareInfoT), (void*)&firmwareInfo}
};

const uint16_t mbMap_size = sizeof(mbMap) / sizeof(mbMap_st);

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#include "mbData_typedef.h"
#include "mbMapper.h"

CoeffT tankThermisterCoeff, probeCoeff;
FirmwareInfoT firmwareInfo;
MeasurementT measurement;
ProductInfoT dispenser;
StatusT appStatus;
TimingT appUpTime;

const mbObjMap_st mbObject[] =
{
    {eThermistorCoeff, (void*)&tankThermisterCoeff},
    {eProbeCoeff, (void*)&probeCoeff},

    {eFirmwareInfo, (void*)&firmwareInfo},

    {eMeasurement, (void*)&measurement},

    {eProductInfo, (void*)&dispenser},

    {eStatus, (void*)&appStatus},

    {eTiming, (void*)&appUpTime}
};
const uint16_t mbObjMap_size = sizeof(mbObject) / sizeof(mbObjMap_st);

const mbMap_st mbMap[] =
{
    {0x1200, sizeof(CoeffT), eThermistorCoeff},
    {0x1240, sizeof(CoeffT), eProbeCoeff},

    {0x1280, sizeof(FirmwareInfoT), eFirmwareInfo},

    {0x12C0, sizeof(MeasurementT), eMeasurement},

    {0x1300, sizeof(ProductInfoT), eProductInfo},

    {0x1340, sizeof(StatusT), eStatus},

    {0x1380, sizeof(TimingT), eTiming}
};

const uint16_t mbMap_size = sizeof(mbMap) / sizeof(mbMap_st);

const mbMemberMap_st mbFieldMap[] =
{
    {eThermistorCoeff, offsetof(CoeffT, coeffA)},
    {eThermistorCoeff, offsetof(CoeffT, coeffB)},
    {eThermistorCoeff, offsetof(CoeffT, coeffC)},

    {eProbeCoeff, offsetof(CoeffT, coeffA)},
    {eProbeCoeff, offsetof(CoeffT, coeffB)},
    {eProbeCoeff, offsetof(CoeffT, coeffC)},

    {eFirmwareInfo, offsetof(FirmwareInfoT, mfcID)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, serial)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, buildDate)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, version)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, hw_version)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, node_address)},
    {eFirmwareInfo, offsetof(FirmwareInfoT, imgVersionBak)},

    {eMeasurement, offsetof(MeasurementT, tank_temp)},
    {eMeasurement, offsetof(MeasurementT, probe_temp)},
    {eMeasurement, offsetof(MeasurementT, weightIn)},
    {eMeasurement, offsetof(MeasurementT, conductivity_lowg)},
    {eMeasurement, offsetof(MeasurementT, conductivity_highg)},

    {eProductInfo, offsetof(ProductInfoT, weight)},
    {eProductInfo, offsetof(ProductInfoT, dispenser_type)},

    {eStatus, offsetof(StatusT, lid_switch)},
    {eStatus, offsetof(StatusT, float_empty)},
    {eStatus, offsetof(StatusT, float_filled)},
    {eStatus, offsetof(StatusT, float_overflow)},
    {eStatus, offsetof(StatusT, float_flush)},
    {eStatus, offsetof(StatusT, water_valve)},
    {eStatus, offsetof(StatusT, pump_recir)},
    {eStatus, offsetof(StatusT, pump_delivery)},
    {eStatus, offsetof(StatusT, mcu)},
    {eStatus, offsetof(StatusT, vin_mon)},
    {eStatus, offsetof(StatusT, comm_mon)},
    {eStatus, offsetof(StatusT, app_ops)},
    {eStatus, offsetof(StatusT, app_alarm)},

    {eTiming, offsetof(TimingT, hourElapsed)},
    {eTiming, offsetof(TimingT, probe_upTime)},
    {eTiming, offsetof(TimingT, processor_upTime)}
};
const uint16_t mbFieldMap_size = sizeof(mbFieldMap) / sizeof(mbMemberMap_st);

static inline void* _getObj(uint16_t reg_address);

/*
 * -----------------------------------------------------------------------------
 * Public functions implementation
 * -----------------------------------------------------------------------------
 */
const mbMap_st* mbMap_getHandle(void)
{
    return &mbMap[0];
}

uint16_t mbMap_getSize(void)
{
    return mbMap_size;
}

const mbObjMap_st* mbObjectMap_getHandle(void)
{
    return &mbObject[0];
}

uint16_t mbObjectMap_getSize(void)
{
    return mbObjMap_size;
}

const mbFieldMap_getHandle(void)
{
    return &mbFieldMap[0];
}

uint16_t mbFieldMap_getSize(void)
{
    return mbFieldMap_size;
}

void mbMap_showMember(void)
{
    uint16_t idx = 0;
    DataObj_enum obj = mbFieldMap[idx].data_obj;
    uint16_t base_address = mbMap_lookupBaseAddress(&mbMap[0], mbMap_size, obj);

    for(idx = 0; idx < mbFieldMap_size; idx++)
    {
        if(obj != mbFieldMap[idx].data_obj)
        {
            obj = mbFieldMap[idx].data_obj;
            base_address = mbMap_lookupBaseAddress(&mbMap[0], mbMap_size, obj);
            printf("\n");
        }

        printf("[%d] member: 0x%x\n", mbFieldMap[idx].data_obj, base_address + mbFieldMap[idx].offset);
    }
}

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
    DataObj_enum data_type = mbMap_lookupDataType(&mbMap[0], mbMap_size, reg_address);
//    printf("DataObj = %d\n", data_type);

    uint16_t idx = mbMap_lookupObj(&mbObject[0], mbObjMap_size, data_type);
//    printf("idx = %d\n", idx);

    return mbMap_getObj(&mbObject[0], idx);
}

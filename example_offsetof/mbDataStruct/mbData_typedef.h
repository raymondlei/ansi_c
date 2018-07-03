#ifndef MBDATA_TYPEDEF_H_
#define MBDATA_TYPEDEF_H_

#include <stdint.h>

#define SIZEOF(s, m)  ((size_t) sizeof(((s *)0)->m))

typedef struct
{
    float coeffA;
    float coeffB;
    float coeffC;
}CoeffT;

typedef struct
{
    uint16_t mfcID;
    uint16_t serial;
    uint16_t buildDate;
    uint8_t version;
    uint8_t hw_version;
    uint8_t node_address;
    uint8_t imgVersionBak;  //firmware image version, backup
}FirmwareInfoT;

typedef struct
{
    uint16_t tank_temp;   //Tank Thermistor Temperature
    uint16_t probe_temp;  //Probe temperature
    uint16_t weightIn;    //weight in value
    uint16_t conductivity_lowg;  //low gain value conductivity
    uint16_t conductivity_highg; //high gain value conductivity
}MeasurementT;

typedef struct
{
    uint16_t weight;  //preset value
    uint8_t dispenser_type;  //oxy, non-oxy
}ProductInfoT;

typedef struct
{
    uint8_t lid_switch;  //lid switch
    uint8_t float_empty, float_filled, float_overflow, float_flush;  //float switches
    uint8_t water_valve;  //water valve
    uint8_t pump_recir, pump_delivery;  //pumps
    uint8_t mcu;    //microcontroller
    uint8_t vin_mon, comm_mon;
    uint8_t app_ops, app_alarm;  //application status
}StatusT;

typedef struct
{
    uint16_t hourElapsed;  //since last maintenance
    uint16_t probe_upTime;    //uptime in hours
    uint16_t processor_upTime;  //MCU uptime in hours
}TimingT;

extern CoeffT tankThermisterCoeff, probeCoeff;
extern FirmwareInfoT firmwareInfo;
extern MeasurementT measurement;
extern ProductInfoT dispenser;
extern StatusT appStatus;
extern TimingT appUpTime;


extern CoeffT* Coeff_getObj(uint16_t reg_address);
extern FirmwareInfoT* FirmwareInfo_getObj(uint16_t reg_address);
extern MeasurementT* Measurement_getObj(uint16_t reg_address);
extern ProductInfoT* ProductInfo_getObj(uint16_t reg_address);
extern StatusT* Status_getObj(uint16_t reg_address);
extern TimingT* Timing_getObj(uint16_t reg_address);

#endif /* MBDATA_TYPEDEF_H_ */

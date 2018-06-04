#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <stdint.h>

//struct member is not shown in header file
struct packet_st;
typedef struct packet_st Packet_st;
typedef struct packet_st * PacketT;

#ifdef __cplusplus
extern "C"
{
#endif
    extern PacketT Component_Construct(void);
    extern void Component_Destruct(PacketT p_obj);

    extern void Component_Init(PacketT p_obj);
    extern void Component_SetAppState(PacketT p_obj, uint16_t value);
    extern void Component_SetTemperature(PacketT p_obj, uint16_t value);
    extern void Component_SetPosition(PacketT p_obj, uint16_t value);

    extern uint16_t Component_GetAppState(PacketT p_obj);
    extern uint16_t Component_GetTemperatre(PacketT p_obj);
    extern uint16_t Component_GetPosition(PacketT p_obj);
#ifdef __cplusplus
}
#endif
#endif /* COMPONENT_H_ */

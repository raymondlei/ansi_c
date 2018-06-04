 /**
 *                                                                    INCLUDE FILES -----
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Component.h"


//Data structure that is kept private
struct packet_st
{
	uint16_t position;
	uint16_t temperature;
	uint16_t appState;
};

/**
*                                                   GLOBAL FUNCTION IMPLEMENTATIONS -----
*/
PacketT Component_Construct(void)
{
	PacketT obj = (PacketT) malloc(sizeof(Packet_st));

	if(obj == NULL) return (NULL);

	return obj;
}

void Component_Destruct(PacketT p_obj)
{
    free(p_obj);
}

void Component_Init(PacketT p_obj)
{
	p_obj->appState = 0;
	p_obj->position = 0;
	p_obj->temperature = 0;
}

void Component_SetAppState(PacketT p_obj, uint16_t value)
{
	p_obj->appState = value;
}

void Component_SetTemperature(PacketT p_obj, uint16_t value)
{
	p_obj->temperature = value;
}

void Component_SetPosition(PacketT p_obj, uint16_t value)
{
	p_obj->position = value;
}

uint16_t Component_GetAppState(PacketT p_obj)
{
	return p_obj->appState;
}

uint16_t Component_GetTemperatre(PacketT p_obj)
{
	return p_obj->temperature;
}

uint16_t Component_GetPosition(PacketT p_obj)
{
	return p_obj->position;
}

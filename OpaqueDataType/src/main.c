/*
 ============================================================================
 Name        : OpaqueDataType.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Demonstrate concept of keeping data structure private
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "Component.h"

int main(void)
{
	uint16_t value;

	PacketT _samplePacket = Component_Construct();
	Component_Init(_samplePacket);
	value = Component_GetPosition(_samplePacket);
	printf("Position: %d\n", value);

	Component_SetPosition(_samplePacket, 20);

	//member of data structure can not be manipulated directly. uncomment code to test
	//_samplePacket.position = 30;

	value = Component_GetPosition(_samplePacket);
	printf("Position: %d\n", value);

	Component_SetPosition(_samplePacket, 56);
	value = Component_GetPosition(_samplePacket);
	printf("Position: %d\n", value);

	return EXIT_SUCCESS;
}

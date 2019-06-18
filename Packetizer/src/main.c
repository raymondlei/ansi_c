#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "Packetizer.h"

#define MAX_PACKET_SIZE     20

static Packetizer_st instance;
static char buf[MAX_PACKET_SIZE];

static void fillContainer(char* outputStr, char value, int count)
{
    int i;
    for(i = 0; i < count; i++)
    {
        outputStr[i] = value;
    }
    outputStr[i] = '\0';
}

static void addPacket(Packetizer_st* obj, char* inputStr)
{
    char* temp;
    temp = Packetizer_addPacket(obj, inputStr);

    if(temp == NULL)
    {
        printf("TX: %s\n", instance.buf);
    }
    else
    {
        printf("TX: %s\n", instance.buf);
        temp = Packetizer_addPacket(&instance, inputStr);
        printf("TX: %s\n", instance.buf);
    }
}

int main(void)
{
	char container[MAX_PACKET_SIZE];

	Packetizer_init(&instance, &buf[0], MAX_PACKET_SIZE);
	printf("TX: %s\n", instance.buf);

	fillContainer(&container[0], 'a', 10);
	printf("container: %s\n", container);
	addPacket(&instance, &container[0]);

	fillContainer(&container[0], 'b', 15);
	printf("container: %s\n", container);

	addPacket(&instance, &container[0]);

	return EXIT_SUCCESS;
}

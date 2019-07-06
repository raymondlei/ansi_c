#include <stdio.h>
#include <stdlib.h>

long toBigEndian(long little_endian)
{
	long result = 0;

	result |= (little_endian & 0x00FF) << 24;
	result |= (little_endian & 0xFF00) << 8;
	result |= (little_endian & 0x00FF0000) >> 8;
	result |= (little_endian & 0xFF000000) >> 24;


	return result;
}

int toBigEndian_test(void) {

    long temp = toBigEndian(0x12345678);
    printf("result = 0x%x", temp);

    return EXIT_SUCCESS;
}

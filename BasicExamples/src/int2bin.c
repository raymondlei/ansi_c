/*
 ============================================================================
 Name        : combinatoric.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 11


// buffer must have length >= sizeof(int) + 1
// Write to the buffer backwards so that the binary representation
// is in the correct order i.e.  the LSB is on the far right
// instead of the far left of the printed string
char *int2bin(int a, char *buffer, int buf_size)
{
	int i;
	buffer += (buf_size - 1);

	for (i = BUF_SIZE; i >= 0; i--)
	{
		*buffer-- = (a & 1) + '0';

		a >>= 1;
	}

	return buffer;
}

void int2bin_test(void)
{
    unsigned int idx;

    char buffer[BUF_SIZE];
    buffer[BUF_SIZE - 1] = '\0';

    for(idx = 0; idx < 1023; idx++)
    {
        int2bin(idx, buffer, BUF_SIZE - 1);
        printf("%s\n", buffer);
    }
}

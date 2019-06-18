#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "Packetizer.h"

static inline void _clearBuf(char* buf, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        buf[i] = '\0';
    }
}

void Packetizer_init(Packetizer_st* obj, char* buf, int size)
{
	obj->buf = buf;
	obj->buf_size = size;
	obj->fill_ptr = obj->buf;
	_clearBuf(obj->buf, obj->buf_size);
}

void Packetizer_clear(Packetizer_st* obj)
{
    _clearBuf(obj->buf, obj->buf_size);
    obj->fill_ptr = obj->buf;  //reset pointer
}

char* Packetizer_addPacket(Packetizer_st* obj, char* inputStr)
{
	while(obj->fill_ptr < obj->buf + obj->buf_size)
	{
		if(*inputStr == '\0')
		{
		    break;
		}
		else
		{
		    *obj->fill_ptr = *inputStr;  //copy content
	        inputStr++;  //increment pointer
	        obj->fill_ptr++;  //increment pointer
		}
	}

	*(obj->fill_ptr) = '\0';
    if(obj->fill_ptr >= obj->buf + obj->buf_size)
    {
        obj->fill_ptr = obj->buf;
        return inputStr;
    }
    else
    {
        return NULL;
    }
}

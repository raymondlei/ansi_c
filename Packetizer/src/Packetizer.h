#ifndef PACKETIZER_H_
#define PACKETIZER_H_

typedef struct
{
    char* buf;
    char* fill_ptr;
    int buf_size;

}Packetizer_st;

#ifdef __cplusplus
extern "C"
{
#endif

    extern void Packetizer_init(Packetizer_st* obj, char* buf, int size);
    extern void Packetizer_clear(Packetizer_st* obj);
    extern char* Packetizer_addPacket(Packetizer_st* obj, char* inputStr);

#ifdef __cplusplus
}
#endif

#endif /* PACKETIZER_H_ */

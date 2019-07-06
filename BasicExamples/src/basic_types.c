#include <stdio.h>

/*
 * Data type
 */
char gC;
unsigned char guC;
signed char gsC;

int gI;
unsigned int guI;

short int gSI;
unsigned short int guSI;

long int gLI;
unsigned long int guLI;

float gF;

short long int gSLI;
unsigned short long int guSLI;
unsigned float guF;

/*
 * Struct
 */
struct {
  int x;
  char y[4];
} s1 = { 0x5A, "abc" };

struct {
  int x[5];
  int y;
} s2 = { { 1, 2, 3, 4, 5 }, 0xA5 };

/*
 * Array
 */
char x[] = "abc";
int i[] = { 1, 2, 3, 4, 5};

void BasicType_test(void)
{
  gC  = 'a';
  guC = 'b';
  gsC = 'c';

  gI  = 10;
  guI = 0xA;

  gSI  = 0b1010;
  guSI = 10u;

  gLI  = 0x1234;
  guLI = 0xFA5A;

  gF  = -1.395;
  guF = 3.14;

  while (1)
    ;
}

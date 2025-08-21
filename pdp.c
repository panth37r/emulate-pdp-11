#include <stdio.h>
#include "pdp.h"
#define MEMSIZE (64*1024)

void b_write(Address a, byte value)
{
   mem[a] = value;    
}

byte b_read(Address a)
{
   return mem[a];
}


void w_write(Address a, word value);
word w_read(Adress a);

int main()
{
    return 0;
}

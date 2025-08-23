#include <stdio.h> 
#include "in-out_stream.h"

#define MEMSIZE (64*1024)
#define REGCOUNT 8

static word mem[MEMSIZE];
static word reg[REGCOUNT];

void b_write(Address a, byte value)
{
	word w_value = value;
	if(a % 2 == 0)
	{
		mem[a] = ((mem[a] & 0xFF00)) | w_value;
    }
	else
    { 
	    mem[a-1] = (mem[a-1] & 0x00FF) | (w_value << 8);
    }	   
}


byte b_read(Address a)
{
  if(a % 2 == 0)
	 return (byte)mem[a]; // return mem[a] & 0xFF
  else 
  {
	word w = mem[a-1];
	byte b = (w >> 8) & 0xFF;
	return b;
  } 
}


void w_write(Address a, word value)
{
	//mem[a] = value & 0x00FF;
	//mem[a+1] = value & 0xFF00;
	mem[a] = value;
}
word w_read(Address a)
{
//	word res = mem[a+1];
//	res << 8;
//	res = res | mem[a];

//	return res & 0xFFFF;
	return mem[a];
}


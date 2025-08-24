#include <stdio.h> 
#include <stdlib.h>
#include "in-out_stream.h"
#include "pdp_mem.h"
#include "log.h"

#define MEMSIZE (64*1024)
#define pc reg[7]

typedef enum {MOV, ADD, HALT, UNKNOWN} mnem;
static word mem[MEMSIZE];
word reg[REGCOUNT];


word inc_pc()
{
	pc = pc + 2; // po idee nujno inc na 1 a ne na 2 no tipo poh
	return pc;
}

void set_pc(word value)
{
	pc = value;
}

word get_pc()
{
	return pc;
}

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






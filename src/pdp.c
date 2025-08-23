#include <stdio.h> 
#include <stdlib.h>
#include "in-out_stream.h"
#include "pdp.h"
#include "log.h"

#define MEMSIZE (64*1024)


typedef enum {MOV, ADD, HALT, UNKNOWN} mnem;
static word mem[MEMSIZE];
word reg[REGCOUNT];



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

mnem check_mnem(mnem value)
{
	
}

void run()
{
	pc = 1000;
	word w;
	while(1)
	{
		w = w_read(pc);
		trace(TRACE, "06o 06o: ", pc, w);
		pc += 2;
	}
}

void do_halt()
{
	trace(INFO, "THE END !\n");
	exit(0);
}



void do_add();
void do_mov();
void do_nothing();

#pragma once

#define REGCOUNT 8
#define pc reg[7]


typedef unsigned char byte;
typedef unsigned short word;
typedef word Address;

extern word reg[REGCOUNT];

byte b_read(Address a);
void b_write(Address a, byte value);


word w_read(Address a);
void w_write(Address a, word value);


void do_halt();

void do_add();
void do_mov();
void do_nothing();

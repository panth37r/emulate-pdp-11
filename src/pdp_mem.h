#pragma once

#define REGCOUNT 8
#define pc reg[7]


typedef unsigned char byte;
typedef unsigned short word;
typedef word Address;

extern word reg[REGCOUNT];


word inc_pc();
void set_pc(word value);
word get_pc();

byte b_read(Address a);
void b_write(Address a, byte value);


word w_read(Address a);
void w_write(Address a, word value);



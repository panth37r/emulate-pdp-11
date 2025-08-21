#pragma once



typedef unsigned byte char;
typedef unsigned short int word;
typedef word Address;

byte b_read(Address a);
void b_write(Address a, byte value);


word w_read(Address a);
void w_write(Address a, word value);


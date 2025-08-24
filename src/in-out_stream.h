#pragma once
#include <stdio.h>
#include "pdp_mem.h"

void load_data(FILE *stream);
void mem_dump(FILE *stream, Address adr, int size);
void load_file(const char* filename);


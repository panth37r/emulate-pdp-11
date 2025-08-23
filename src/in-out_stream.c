#include "pdp.h"
#include <stdio.h>
#include <stdlib.h>

void load_data(FILE *stream)
{
	Address adr;
	word count;
	byte data;
	while(fscanf(stream, "%hx %hx", &adr, &count) == 2)
	{
		for(int i = 0; i < count; i++)
		{
			fscanf(stream, "%hhx", &data);
			b_write(adr+i, data);
		}
	}
}

void mem_dump(FILE *stream, Address adr, int size)
{
	for(int i = 0; i < size; i += 2)
	{
		fprintf(stream, "%06o: %06o %04x\n", adr+i, w_read(adr+i), w_read(adr+i));
	}
}



void load_file(const char* filename)
{
	FILE *stream = fopen(filename, "r");
	if(stream == NULL)
	{
		perror("Error: can't open file");
		exit(1);
	}
	load_data(stream);
	fclose(stream);
}

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pdp.h" 
#include "in-out_stream.h"



char *get_filename(int argc, char *arg_v[])
{
	for (int i = 0; i < argc; i++)
		if(strcmp(arg_v[i], "-t") == 0)
			return arg_v[i+1];
	return NULL;
}


int main(int argc, char *arg_v[])
{
	if(argc <= 1)
	{
		perror("Enter a filename after -t flag\n");
		exit(1);
	}
	int opt = 0;
	char *filename = 0;
	while((opt = getopt(argc, arg_v, "t:")) != -1)
	{
		switch(opt)
		{
			case 't':
				filename = optarg;
		}	
	}
	printf("%s\n", filename);
	load_file(filename);
	mem_dump(stderr, 0, 20);
	return 0;
}

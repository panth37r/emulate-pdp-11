#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pdp.h" 
#include "in-out_stream.h"
#include "log.h"


void temp_main(int argc, char *arg_v[])
{
	if(argc <= 1)
	{
		perror("Enter a filename after -t flag\n");
		exit(1);
	}
	int opt = 0;
	char *filename = 0;
	while((opt = getopt(argc, arg_v, "f:t")) != -1)
	{
		switch(opt)
		{
			case 'f':
				filename = optarg;
				break;
			case 't':
				set_log_level(TRACE);
				break;
		}	
	}
	printf("%s\n", filename);
	load_file(filename);
	mem_dump(stderr, 0, 20);

}

int main(int argc, char *arg_v[])
{
	set_log_level(INFO);
	do_halt();
	return 0;
}

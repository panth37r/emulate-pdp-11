// stl
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//main logic of programm
#include "pdp_mem.h"
#include "pdp_func.h"
// input-output, logs
#include "in-out_stream.h"
#include "log.h"

void temp_main(int argc, char *arg_v[])
{
//	printf("%s\n", filename);
//	load_file(filename);
//	mem_dump(stderr, 0, 20);

}

int main(int argc, char *arg_v[])
{
	set_log_level(INFO);
	
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
	do_add();
	do_nothing();
	do_mov();
	do_halt();
	return 0;
}

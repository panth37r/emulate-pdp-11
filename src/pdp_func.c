#include <stdlib.h>
#include "log.h"
#include "pdp_mem.h"
#include "pdp_func.h"


#define C_FUNC 3

struct Command
{
	word mask;
	word opcode;
	char *name;
	void (*func_name)(void);
};

Command cmd_list[] = 
{
	{0111111, 0000000, "halt", do_halt},
	{0170000, 0010000, "mov", do_mov},
	{0170000, 0060000, "add", do_add},
	{0111111, 0111111, "unknown", do_nothing}
};

void do_halt()
{
	trace(TRACE,"THE END\n");
	exit(0);
}
void do_add()
{
	trace(TRACE, "add\n");
}
void do_mov()
{
	trace(TRACE, "mov\n");
}
void do_nothing()
{
	trace(TRACE, "unknown\n");
}
void run()
{
	set_pc(01000);
	
	while(1)
	{
		word w_cur = w_read(pc);
		trace(TRACE, "%06o %06o: ", get_pc(), w_cur);	
		inc_pc();

		for(int i = 0; i < C_FUNC; i++)
		{
			Command cur_cmd = cmd_list[i];
			if((w_cur & cur_cmd.mask) == cur_cmd.opcode)
			{
				cur_cmd.func_name();
				break;
			}
		}
	}
}

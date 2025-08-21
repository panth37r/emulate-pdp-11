#include <assert.h>
#include <stdio.h>
#include <pdp.h>

int main()
{
	byte b0, b1 b_res;
	word w, w_res;
	
	frintf(stderr, "Write byte and read by 2//0 address\n");
	a = 0;
	b0 = 0x12;
	b_write(a, b0);
	b_res = b_read(a);
	fprintf(stderr, "a=%06o b0=%02hhx b_res=%02hhx", a, b0, b_res);
	assert(b0 == b_res);

	fprintf(stderr, "Write word and read\n");
	a = 2;
	w = 0x3456;
	w_write(a, w);
	w_res = w_read(a);
	fprintf(stderr, "a=%06o w=%04x w_res=%04x \n", a, w, w_res);
	assert(w == w_res);

	fprinf(stderr, "Write 2 byte and read word\n");
	a = 4;
	b0 = 0x16;
	b1 = 0x32;
	w = 0x3216;
	b_write(a, b0);
	b_wirte(a+1, b1);
	w_res = w_read(a);
	fprintf(stderr, "a=%06o b1=%02hhx b2=%02hhx wres=%04x\n", a, b0, b1, w_res);
	assert(w == w_res);

	return 0;
}

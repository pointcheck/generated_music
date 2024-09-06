// Written by Ruslan Zalata <rz@fabmicro.ru>
// Ideas from: https://www.youtube.com/watch?v=tCRPUv8V22o

#include <stdio.h>
#include <stdlib.h>

char *dsp_dev = "/dev/dsp1.0";

int main(int argc, char *argv[]) {
	int samples = 1000000;

	if(argv[1])
		samples = atoi(argv[1]);

	FILE *dsp = fopen(dsp_dev, "a+b");
	
	if(!dsp) { 
		perror("fopen");
		return -1;
	}
 
	for(int t=0;samples;t++,--samples)
		fputc(t*(t^t+(t>>15|1)^(t-1280^t)>>10), dsp);

	return 0;
}

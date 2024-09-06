// Written by Ruslan Zalata <rz@fabmicro.ru>
// Ideas from: https://www.youtube.com/watch?v=tCRPUv8V22o

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>

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
 
	int param = 44100;
	ioctl(fileno(dsp), SNDCTL_DSP_SPEED, &param);


	for(int t=0;samples;t++,--samples)
		fputc(
			((t/2*(15&(0x2345678a0>>(t>>8&28))))|t/2>>(t>>11)^t>>12)+(t/16&t&24),
		dsp);

	return 0;
}

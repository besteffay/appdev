// this file will be used to test functions in tscreen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void)
{
	clearscreen();
	FILE *fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	getchar();
	wavdata(h, fp);
	fclose(fp);
}

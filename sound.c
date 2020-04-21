#include <stdio.h>
#include <math.h>
#include "sound.h"
#include "screen.h"


// function definitions

WAVheader readwavhdr(FILE *fp)
{
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h)
{
	for(int i=0; i<4; i++)
	{
		printf("%c", h.chunkID[i]);
	}
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);
	// to be continued
	double duration;
	duration = (double)h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n", duration);
}

void wavdata(WAVheader h, FILE *fp)
{
	// For sample rate 16000sps, we need to read 2000 samples to calculate a
	//	"Fast" decibel value. A decibel value is always calculated by RMS
	//	(Root Means Square) formula.
//	clearscreen();
	short samples[SIZE];
	int peaks=0;
	int flag=0;
	for(int i=0; i<BARS; i++)			// to read 5sec wave file, we have 40 data
	{
		fread(samples, sizeof(samples), 1, fp);
		double sum=0.0;
		for(int k=0; k<SIZE; k++)
		{
			sum = sum + samples[k]*samples[k];
		}
		//double dB = sqrt(sum/2000);
		double dB = 20*log10(sqrt(sum/SIZE));

		#ifdef SDEBUG
			printf("dB[%d] = %f\n", i, dB);
		#else
			if(dB>70)
			{
				setfgcolor(RED);
				if(flag==0)
				{
					peaks++;
					flag=1;
				}
			}
			else
			{
				setfgcolor(WHITE);
				if(flag==1)
					flag=0;
			}
			drawbar(i+1, (int)dB/3);
			gotoXY(1,1);
			setfgcolor(CYAN);
			printf("Sample rate: %d\n", h.sampleRate);
			gotoXY(1,75);
			setfgcolor(MAGENTA);
			printf("Duration: %.2f seconds\n", (double)h.subchunk2Size/h.byteRate);
			gotoXY(1,140);
			setfgcolor(YELLOW);
			printf("Number of peaks: %d\n", peaks);
			resetcolor();
		#endif
	}
	printf("\n\n");
}

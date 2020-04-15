// this file will be used to test functions in tscreen.c

#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"

int main(void)
{
	Position cur = getscreensize();			// get screen size
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900301", cur.row, cur.col);
	sendpost(URL, postdata);
	gotoXY(1,1);
	printf("Screen size: row = %d, col = %d\n", cur.row, cur.col);
	//clearscreen();
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar();
	int ff, bb, ffr;
	float step = ((float)cur.col/cur.row)/2;

	for(int i=1; i<=cur.row; i++)
		{
			ff = RED;
			bb = BLACK;
			ffr = GREEN;

			setcolors(ff, bg(bb));
			clearscreen();
			if(i<=cur.row)
			{
				gotoXY(cur.row-i, (i-1)*step+1);
				printf("HELLO\n");
				setfgcolor(ffr);
				drawrect(i, (i-1)*step+1, 2, 4);
				sleep(1);
			}
			else
			{
				gotoXY(i-cur.row-2, (i-1)*step+1);
				printf("HELLO\n");
				setfgcolor(ffr);
				drawrect(cur.row-1-i, (i-1)*step+1, 2, 4);
				sleep(1);
			}
		}
/*
	for(int i=1; i<51; i++)
	{
		ff = RED;
		bb = BLACK;
		setcolors(ff, bg(bb));
		clearscreen();
		if(i<26)
		{
			drawrect(i, (i-1)*1.5+1, 2, 4);
			sleep(1);
		}
		else
		{
			drawrect(49-i, (i-1)*1.5+1, 2, 4);
			sleep(1);
		}
	}
*/
	getchar();
	resetcolor();
	clearscreen();
	printf("Colors are reset\n");
	getchar();
/*
	clearscreen();
	setfgcolor(CYAN);
	gotoXY(14, 35);
	printf("HELLO, WORLD!\n");
	getchar();
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();
	resetcolor();
	printf("This reset the color.\n");
*/	
}

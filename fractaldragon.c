#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapeslib.h"
#include <stdlib.h>

int main(int argc, char * argv[])
{

	double limit;
	int delay;
	if (argc >= 3) {
		sscanf(argv[1],"%lf",&limit);
		sscanf(argv[2], "%d",&delay);
	} else {
	printf("Missing command line arguement!\n");
	printf("usage: testDragon minSegmentLength\n");
	exit(1);	
	}
	
	int ysize = 600;
	int xsize = 600;
	char c;
	// Open a new window
	gfx_open(xsize,ysize,"Example Graphics Program");
	//set the current drawing color to green
	gfx_color(0,255,100);

	GfxPoint first = { .x=200, .y=200},	last = { .x=400, .y=400 };
	
	drawDragon(first,last,limit,delay);

	while(1) {
		c = gfx_wait();

		if(c=='q') break;
	}
	
	return 0;
}

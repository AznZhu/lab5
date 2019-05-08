#include <stdio.h>
#include "gfx2.h"
#include "myGfxShapeslib.h"
#include <stdlib.h>

int main(){
	int ysize = 800;
	int xsize = 800;
	int R=20,G=20,B=255;
	float baseX =0, baseY=0, branchLength=100, branchAngle=10, lengthRatioA=.4, lengthRatioB=.6, branchAngleA=40, branchAngleB=40, minimumBranchLength=1;
	char c;

	// Set the current drawing color to user input
	printf("Enter RGB values :\n");
	scanf("%d %d %d", &R, &G ,&B);
	printf("Starting Position (x,y):\n");
	scanf("%f %f", &baseX, &baseY);
	printf("Branch Length:\n");
	scanf("%f", &branchLength);
	printf("Branch Angle:\n");
	scanf("%f", &branchAngle);
	printf("Length Ratio A between 0 and 1:\n");
	scanf("%f", &lengthRatioA);
	printf("Length Ratio B between 0 and 1:\n");
	scanf("%f", &lengthRatioB);
	printf("Branch Angel A:\n");
	scanf("%f", &branchAngleA);
	printf("Breanch Angel B:\n");
	scanf("%f", &branchAngleB);
	printf("Minimum Branch Length:\n"); 
	scanf("%f", &minimumBranchLength);
	
	// Open a new window for drawing

	gfx_open(xsize,ysize,"trees");
	
	gfx_color(R, G, B);

	
	RecursiveTree(baseY+400, baseX+400, branchLength, branchAngle, lengthRatioA, lengthRatioB, branchAngleA, branchAngleB, minimumBranchLength);
	
while(1) {
		c = gfx_wait();

		if(c=='q') break;
	}

return 0;
}

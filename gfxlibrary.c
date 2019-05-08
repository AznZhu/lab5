#include <stdio.h>
#include "gfx2.h"
#include <math.h>
#include "myGfxShapeslib.h"
#include <unistd.h>


double pi =3.14159265359;

void drawSquare(double xCenter, double yCenter, double side)
{
	//calculates coordinates of all corners
	double ulx = xCenter - side/2;
	double uly = yCenter - side/2;
	double llx = xCenter - side/2;
	double lly = yCenter + side/2;
	double urx = xCenter + side/2;
	double ury = yCenter - side/2;
	double lrx = xCenter + side/2;
	double lry = yCenter + side/2;

	gfx_line(ulx, uly, llx, lly);
	gfx_line(llx, lly, lrx, lry);
	gfx_line(lrx, lry, urx, ury);
	gfx_line(urx, ury, ulx, uly);
}

void drawCircle(double xCenter, double yCenter, double radius)
{
    double x,y,theta,xNext,yNext,thetaNext;
    double thetaIncrement = 0.1;
    for( theta = 0; theta < 2*pi; theta = thetaNext)
    {
        thetaNext = theta + thetaIncrement;
        x = xCenter + radius *cos(theta);
        y = yCenter + radius *sin(theta);
        xNext = xCenter + radius * cos(thetaNext);
        yNext = yCenter + radius * sin(thetaNext);
        gfx_line(x,y,xNext,yNext);
    }
}

void drawBars(double * data, int datacount, double lowerleftX, double lowerleftY,
			double width, double spacing){

	printf("drawBars: Not fully implemented\n");
	int i;
	double llx = lowerleftX;
	double lly = lowerleftY;
	
	for (i=0; i < datacount; i++)
	{
	//draw the rectangle for the correct height and width in the correct position
	gfx_line(llx,lly, llx, lly-data[i]); //draw the left side of the rectangle
	gfx_line(llx,lly,llx + width,lly);//draw bottom
	gfx_line(llx + width, lly, llx + width, lly-data[i]);//draw right side
	gfx_line(llx,lly-data[i], llx + width, lly-data[i]);//draw top
	llx = llx + spacing + width;
	
	}	
	
	gfx_flush();	
	
}
void drawCharC(double upperleftx, double upperlefty, double height)
{
	double ulx = upperleftx;
	double uly = upperlefty;
	double llx = upperleftx;
	double lly = upperlefty + height;
	double urx = upperleftx + height*.6;
	double ury = upperlefty;
	double lrx = upperleftx + height*.6;
	double lry = upperlefty + height;
	double ulxs = upperleftx + height*.2;
	double ulys = upperlefty + height*.2;
	double llxs = upperleftx + height*.2;
	double llys = upperlefty + height*.8;
	double urxs = upperleftx + height*.6;
	double urys = upperlefty + height*.2;
	double lrxs = upperleftx + height*.6;
	double lrys = upperlefty + height*.8;

	gfx_line(ulx, uly, llx, lly);
	gfx_line(llx, lly, lrx, lry);
	//gfx_line(lrx, lry, urx, ury);
	gfx_line(urx, ury, ulx, uly);
	gfx_line(ulxs, ulys, llxs, llys);
	gfx_line(llxs, llys, lrxs, lrys);
	//gfx_line(lrxs, lrys, urxs, urys);
	gfx_line(urxs, urys, ulxs, ulys);
	gfx_line(lrx, lry, lrxs, lrys);
	gfx_line(urx, ury, urxs, urys);
}

void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount)
{
	int i;
	int lastPointIndex = coordCount -1;
	int secondToLastIndex = lastPointIndex - 1;
	for (i=0; i <=secondToLastIndex; i++)
	{
		gfx_line(xCoords[i], yCoords[i], xCoords[i+1], yCoords[i+1] );
		
	}
	
	gfx_line(xCoords[i], yCoords[i], xCoords[0], yCoords[0] );
}	

void drawPolygon(GfxPoint * points, int pCount)
{
	int i;
	int lastPointIndex = pCount -1;
	int secondToLastIndex = lastPointIndex -1;
	//loop over index
	for (i=0; i <= lastPointIndex; i++)
	{
		
		gfx_line( points[i].x, points[i].y, points[(i+1)%pCount].x, points[(i+1)%pCount].y );
	}
	//gfx_line(points[i].x, points[i].y, points[0].x, points[0].y);
}

	void drawcirclething(double xCenter, double yCenter, double radius) 
{ 
if (radius > 15) 
	{ 
	//draws main circle 
	drawCircle(xCenter,yCenter,radius); 
	//draws left circle 
	drawcirclething(xCenter-radius,yCenter,radius/2); 
	//draws right circle 
	drawcirclething(xCenter+radius,yCenter,radius/2); 
	} 
} 

void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit, int timeDelay)
{
	GfxPoint newPoint;
	double xdif = b.x-a.x;
	double ydif = b.y-a.y;
	
	double dist = sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
		
	if ( dist <= sizeLimit )
	{
		gfx_line(a.x,a.y,b.x,b.y);
		gfx_flush();
		usleep(timeDelay);
	}
	else
	{
		newPoint.x = a.x + (b.x-a.x)/2 + (b.y-a.y)/2;
		newPoint.y = a.y + (b.y-a.y)/2 - (b.x-a.x)/2;
		
		drawDragon(a,newPoint, sizeLimit, timeDelay);
		drawDragon(b,newPoint, sizeLimit, timeDelay);
		
	}


}


void RecursiveTree(double baseX, double baseY, double branchLength, double branchAngle, double lengthRatioA, double lengthRatioB, double branchAngleA, double branchAngleB, double minBranchLength)
{
	if(branchLength > minBranchLength){
		
	//convert degrees to rads
		branchAngle = ((branchAngle / 360) * 3.14);
		branchAngleA = ((branchAngleA / 360) * 3.14);
		branchAngleB = ((branchAngleB / 360) * 3.14);
		
		branchAngleA += branchAngle;
		branchAngleB += branchAngle;
			
	double baseAX; 
	double hehe =cos(branchAngle/2);
	baseAX	= branchLength * hehe;
	//printf("%lf" , branchAngle);
	double baseAY = branchLength * sin(branchAngle/2);	
	double baseBX = branchLength * -1 * cos(branchAngle/2);
	double baseBY = branchLength * sin(branchAngle/2);	
	//make coords relative
	baseAX += baseX;
	baseAY += baseY;
	baseBX += baseX;
	baseBY += baseY;   
	//convert rads to degrees
		branchAngle = ((branchAngle / 3.14) * 360);
		branchAngleA = ((branchAngleA / 3.14) * 360);
		branchAngleB = ((branchAngleB / 3.14) * 360);
		
	//drawing two lines
	
	gfx_line(baseX, baseY, baseAX, baseAY);
	gfx_line(baseX, baseY, baseBX, baseBY);
	
	
	//A branches
	RecursiveTree(baseAX ,baseAY ,branchLength*lengthRatioA ,branchAngleA ,lengthRatioA ,lengthRatioB ,branchAngleA ,branchAngleB , minBranchLength);
	//B branches
	RecursiveTree(baseBX ,baseBY ,branchLength*lengthRatioB ,branchAngleB ,lengthRatioA ,lengthRatioB ,branchAngleA ,branchAngleB , minBranchLength);
	}
}

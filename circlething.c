#include <stdio.h> 
#include <math.h> 
#include "gfx2.h" 
#include "myGfxShapeslib.h"


// formula for the fibonacci sequence 
int fib(int n) 
{ 
	if(n<=1) { 
	return n; 
	} else { 
		return fib(n-1) + fib(n-2); 
	} 
 
} 

 
int main(int argc, char * argv[]) 
{ 
	int ysize = 500; 
	int xsize = 500; 
	double radius; 
	double XC; 
	double YC; 
	char temp; 
	char c; 
	char p; 
	while(1) 
	{ 
	printf("Enter a center and a radius: "); 
	scanf("%lf", &XC); 
	scanf("%lf", &YC); 
	scanf("%lf", &radius); 
	scanf("%c", &temp); 
	// Open a new window for drawing. 
	gfx_open(xsize,ysize,"Circle Thing"); 
 
	// Set the current drawing color to green. 
	gfx_color(100,250,167); 
	drawCircle(XC,YC,radius); 
	drawcirclething(XC,YC,radius); 
	//asks user to continue or not 
	printf("continue? (n to quit): "); 
  
	scanf("%c", &p);	 
	scanf("%c", &p); 
	//if to decide whether to continue 
	if (p == 'n') 
	{ 
	break; 
	} 
		c = gfx_wait(); 
	} 
 
	return 0; 
}

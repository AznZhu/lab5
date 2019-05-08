/*#include "gfx2.h"

#include "math.h"
#define M_PI 3.14159265358979323846
*/
typedef struct GfxPoint
{
	double x;
	double y;
} GfxPoint;

void drawSquare(double xCenter, double yCenter, double side);
void drawCircle(double xCenter, double yCenter, double radius);
void drawBars(double * data, int datacount, double lowerleftX, double lowerleftY, double width, double spacing);
void drawCharC(double upperleftx, double upperlefty, double height);
void drawcirclething(double xCenter, double yCenter, double radius);  
void drawPolygon(GfxPoint * points, int pCount);
void drawPolygonWithoutStructs(double * xCoords, double * yCoords, int coordCount);
void drawDragon(GfxPoint a, GfxPoint b, double sizeLimit, int timeDelay);
void RecursiveTree(double baseX, double baseY, double branchLength, double branchAngle, double lengthRatioA, double lengthRatioB, double branchAngleA, double branchAngleB, double minBranchLength);

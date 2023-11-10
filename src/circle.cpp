#include "circle.h"

void getCircle(double x, double y, double r,double d, std::vector <Point> &res)
{
	const double pi2 = 8*atan(1), del = 1./r;
	double tx = r, ty = 0;
	for (double i=0; i<=pi2; i+=del)
	{
		res.push_back({x+tx, d, y+ty});
		tx -= ty*del, ty += tx*del;
	}
}
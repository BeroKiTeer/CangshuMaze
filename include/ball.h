#pragma once
#include <vector>

struct Point;

Point getPoint(double u, double v);

void getBall(double x, double y, double z,double size, std::vector <Point> &ball, int acc);
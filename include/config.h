#pragma once
#include <cmath>
#include "ball.h"
#include "line.h"
#include "circle.h"
const double WHITE[3] = {1, 1, 1};
const double RED[3] = {1, 0, 0};
const double YELLOW[3] = {1, 1, 0};
const double GREEN[3] = {0, 1, 0};
const double BLACK[3] = {-1, -1, -1};
const double DARKBLUE[3] = {0.2, 0.2, 0.6};
const double DARKRED[3] = {0.6, 0.2, 0.2};
const double DARKGREEN[3] = {0.2, 0.6, 0.2};
const double PI = 4*atan(1);
struct Point {
    double x,y,z;
    Point() = default;
    ~Point() = default;
    Point(double x, double y, double z):x(x),y(y),z(z){}
};
struct Point2d {
    double x,y;
    Point2d(double x, double y):x(x),y(y){}
};
const UINT WindowsWidth = 800;
const UINT WindowsHeight = 800;
#define ACTCOLOR WHITE
#define GROUNDCOLOR RED
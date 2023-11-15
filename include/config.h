#pragma once
#include <cmath>
#include "line.h"
#include "circle.h"
typedef unsigned int UINT;
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
struct Point2d{
    double x, y;
    Point2d():x(0.0),y(0.0){};
    Point2d(double x, double y):x(x),y(y){};
};
<<<<<<< HEAD

//编译会出错，只能定义常量
//mingw-make clean之后看看结果
//先清理在编译
// int a;

const UINT WindowsWidth = 800;
const UINT WindowsHeight = 800;
const UINT SmallMapSizeINT = 400;
const double SmallMapSizeDouble = 10.0;
=======
const UINT WindowsWidth = 800;
const UINT WindowsHeight = 800;
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
#define ACTCOLOR WHITE
#define GROUNDCOLOR RED
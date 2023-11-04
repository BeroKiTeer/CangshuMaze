#include <cmath>
#include <corecrt_math.h>
#include "ball.h"
#include "line.h"
const double WHITE[3] = {1, 1, 1};
const double RED[3] = {1, 0, 0};
const double YELLOW[3] = {1, 1, 0};
const double GREEN[3] = {0, 1, 0};
const double BLACK[3] = {-1, -1, -1};
const double DARKBLUE[3] = {0.2, 0.2, 0.6};
const double DARKRED[3] = {0.6, 0.2, 0.2};
const double DARKGREEN[3] = {0.2, 0.6, 0.2};
const double PI = 4*tan(1);
struct Point {
    double x,y,z;
};
#define ACTCOLOR WHITE
#define GROUNDCOLOR RED
#pragma once
#include "config.h"
#include "randomwall.h"
#include <GL/freeglut.h>
class SmallMap{
public:
    static void DrawMap(const RandomWallXOY& wall,const Point2d& pos, double Long);
};
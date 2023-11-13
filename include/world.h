#pragma once

#include<GL/glut.h>
#include "transform.h"
#include "shader.h"

class World{
public:
    //初始化所有变量
    World();
    void DrawCoordinate();
    void DrawTestMaze();
private:
    VP CoordinatePoint;
    UINT flood, wall;
    //坐标系
    const float coordinate[4][3] =
    {
        0.0f,0.0f,0.0f,
        10.0f, 0.0f, 0.0f,
        0.0f, 10.0f, 0.0f,
        0.0f, 0.0f, -1.0f
    };

    //坐标系连接线
    const int coordinateList[3][2] = {
        {0, 1},
        {0, 2},
        {0, 3}
    };
};
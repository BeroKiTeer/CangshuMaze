#pragma once

#include<GL/glut.h>
#include "transform.h"
#include "shader.h"

class World{
public:
    //初始化所有变量
<<<<<<< HEAD
    World(){
        for(int i = 0; i < 4; i++){
            CoordinatePoint.push_back(Point(
                coordinate[i][0],coordinate[i][1],coordinate[i][2]
            ));
        }
        flood = 0; wall = 0;
    };
    void DrawCoordinate();
    void DrawTestMaze(int SmallMap);
=======
    World();
    void DrawCoordinate();
    void DrawTestMaze();
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
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
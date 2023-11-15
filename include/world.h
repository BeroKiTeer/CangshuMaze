#pragma once

#include<GL/glut.h>
#include "transform.h"
#include "shader.h"
#include "sharedData.h"

extern GLuint TextureWallID;
extern GLuint TextureFloorID;
extern GLuint TextureTextcurbID;

class World{
public:
    //初始化所有变量
    World(){
        for(int i = 0; i < 4; i++){
            CoordinatePoint.push_back(Point(
                coordinate[i][0],coordinate[i][1],coordinate[i][2]
            ));
        }
        classflood = TextureFloorID; classwall = TextureWallID;
    };
    void DrawCoordinate();
    void DrawTestMaze(int SmallMap);
private:
    VP CoordinatePoint;
    GLuint classflood, classwall;
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
#pragma once

#include<GL/glut.h>
#include<iostream>
#include <cmath>
#include <functional>
#include "transform.h"
#include "shader.h"

class World{
public:
    //初始化所有变量
    World();
    void ShowWorld(int argc, char **argv, GLuint width, GLuint Height );

    void CreateMazeWall();

    static void Test()
    {
        getInstance()->renderScene();
    }

    
    static void Test2(unsigned char key,int x,int y)
    {
        getInstance()->KeyBoards(key,x,y);
    }

    static World* getInstance()
    {
        static World instance;
        return &instance;
    }

private:
    //Implement Cpp
    void CreateMazeBox();
    void KeyBoards(unsigned char key,int x,int y);
    void renderScene();
    void SetCamera(
        double x, double y, double z, double CameraDistance,
        double LookX, double LookY, double LookZ,
        double angleX, double angleY
    );
    void DrawCoordinate();
    void DrawCube();
    //Implement Here
    void ResetTestCurb(){
        UINT size = TestCurbPoint.size();
        TestCurbPoint.clear();
        for(int i = 0; i < size; i++){
            TestCurbPoint.push_back(Point(
                TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]
            ));
        }
    };
    void ResetCoordinatePoint()
    {
        UINT size = CoordinatePoint.size();
        CoordinatePoint.clear();
        for(int i = 0; i < size; i++){
            CoordinatePoint.push_back(
                Point(
                    coordinate[i][0],coordinate[i][1],coordinate[i][2]
            ));
        }
    };
private:
    double angleX = 0.0, angleY = 0.0, CameraDistance = 0.3; //相机的角度和距离
    double x = 0.1, y = 0.2, z = 1.5; //人物在空间中的位置
    GLuint flood = 0,wall = 0;  //墙和地板的纹理ID数值
    VP TestCurbPoint, CoordinatePoint;

    //测试立方体
    const float TestCurb[8][3] = 
    { 
        -0.2f, -0.2f, -0.2f,
        0.2f, -0.2f, -0.2f,
        -0.2f, 0.2f, -0.2f,
        0.2f, 0.2f, -0.2f,
        -0.2f, -0.2f, 0.2f,
        0.2f, -0.2f, 0.2f,
        -0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f
    }; 

    //测试立方体连接线段
    const GLint TestCurbList[12][2] = 
    { 
        {0, 1},    
        {2, 3},    
        {4, 5},    
        {6, 7},    
        {0, 2},    
        {1, 3},    
        {4, 6},    
        {5, 7},
        {0, 4},
        {1, 5},
        {7, 3},
        {2, 6}
    }; 
    
    //坐标系
    const float coordinate[4][3] =
    {
        0.0f,0.0f,0.0f,
        5.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 5.0f
    };

    //坐标系连接线
    const int coordinateList[3][2] =
    {
        {0, 1},
        {0, 2},
        {0, 3}
    };
};
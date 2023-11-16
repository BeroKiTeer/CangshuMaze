#pragma once
#include "gl/freeglut.h"
#include "config.h"
#include "transform.h"
#include "shader.h"
#include "sharedData.h"
#include "listener.h"
#include "randomwall.h"
#include <vector>

#define GLUT_WHEEL_UP 3
#define GLUT_WHEEL_DOWN 4

extern GLuint TextureWallID;
extern GLuint TextureFloorID;
extern GLuint TextureTextcurbID;
extern RandomWallXOY wall;

class Camera : public Listener 
{
public:
    Camera();
    ~Camera()=default;

    void DisableFirstPerson(){
        if(get_EnableCameraDistance() == false){
            set_CameraDistance(get_EnableCameraLastDistance());
        }
        set_EnableCameraDistance(true);
    }
    void EnableFirstPerson(){
        if(get_EnableCameraDistance()){
            set_EnableCameraLastDistance(get_CameraDistance());
        }
        set_EnableCameraDistance(false);
        set_CameraDistance(0.1);
    }
    void ShowTestCurb(int SmallMap);
    void ShowCamera();
    static Camera* getInstance(){
        static Camera instance;
        return &instance;
    }
    
    void Init();

    void SetCamera(
        double x, double y, double z, double CameraDistance,
        double LookX, double LookY, double LookZ,
        double angleY, double angleZ);
    //事件监听
    static void OCameraKeyboard(unsigned char key, int x, int y){
        getInstance()->CameraKeyboard(key,x,y);
    }

    static void OCameraMouseClick(int button, int state, int x, int y){
        getInstance()->CameraMouseClick(button,state,x,y);
    }

    static void OCameraMotion(int x, int y){
        getInstance()->CameraMotion(x,y);
    }

    Point2d getTestCurbPos2D(){
        return Point2d(get_TestCurbX(), get_TestCurbY());
    }

    Point getTestCurbPos3D(){
        return Point(get_TestCurbX(), get_TestCurbY() , get_TestCurbZ());
    }

    double getTestCurbLong(){
        return 0.08*scale;
    }
private:
    void CameraKeyboard(unsigned char key, int x, int y);
    void CameraMouseClick(int btu, int state, int x, int y);
    void CameraMotion(int x, int y);
    void shaderTestCurb(VP& TestCurbPoint, int SmallMap);
    OrientWASD CanMove(
        const RandomWallXOY& wall, const Point2d& point, 
        double Longx, double Longy
    );
private:
    // double TestCurbX,TestCurbY,TestCurbZ;      //测试立方体坐标
    // VP TestCurbPoint, TestCurbShaderPoint;                       //测试立方体
    // UINT TestCurbShaderID;                  //测试立方体渲染ID
    // double scale;                           //测试立方体的缩放
    //测试立方体点集信息
    // const float TestCurb[8][3] = 
    // { 
    //     0.00f, 0.00f, 0.00f,  //0
    //     0.08f, 0.00f, 0.00f,  //1
    //     0.08f, 0.00f, -0.08f, //2
    //     0.00f, 0.00f, -0.08f, //3
    //     0.00f, 0.08f, 0.00f,  //4
    //     0.08f, 0.08f, 0.00f,  //5
    //     0.08f, 0.08f, -0.08f, //6
    //     0.00f, 0.08f, -0.08f  //7
    // }; 

    // //测试立方体连接线段
    // const GLint TestCurbList[12][2] = 
    // { 
    //     {0, 1},    
    //     {3, 2},    
    //     {7, 6},    
    //     {4, 5},    
    //     {0, 3},    
    //     {1, 2},    
    //     {5, 6},    
    //     {4, 7},
    //     {0, 4},
    //     {1, 5},
    //     {7, 3},
    //     {2, 6}
    // };

    
};
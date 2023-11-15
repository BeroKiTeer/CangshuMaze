#pragma once
#include "gl/freeglut.h"
#include "config.h"
#include "transform.h"
#include "shader.h"

#define GLUT_WHEEL_UP 3
#define GLUT_WHEEL_DOWN 4

class Camera{
public:
<<<<<<< HEAD
    Camera(){
        TestCurbX = 0.0; TestCurbY = 0.0; TestCurbZ=0.0;
        angleY = 15.0; angleZ=-90.0; CameraDistance = 1.0;
        LMouseDown = false, RMouseDown = false;
        LMouseDownX = 0, LMouseDownY = 0;
        DealyTime = 0;
        EnableCameraDistance = true;
        EnableCameraLastDistance = 1.0;
        TestCurbShaderID = 0;
        scale = 0.4;
    };
=======
    Camera();

    ~Camera() = default;
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    void DisableFirstPerson(){
        if(EnableCameraDistance == false){
            CameraDistance = EnableCameraLastDistance;
        }
        EnableCameraDistance = true;
    }
    void EnableFirstPerson(){
        if(EnableCameraDistance){
            EnableCameraLastDistance = CameraDistance;
        }
        EnableCameraDistance = false;
        CameraDistance = 0.1;
    }
<<<<<<< HEAD
    void ShowTestCurb(int SmallMap);
=======
    void ShowTestCurb();
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
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
<<<<<<< HEAD
=======

    static void OCameraMotion(int x, int y){
        getInstance()->CameraMotion(x,y);
    }
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8

    static void OCameraMotion(int x, int y){
        getInstance()->CameraMotion(x,y);
    }

    Point2d getTestCurbPos2D(){
        return Point2d(TestCurbX, TestCurbY);
    }

    Point getTestCurbPos3D(){
        return Point(TestCurbX, TestCurbY, TestCurbZ);
    }

    double getTestCurbLong(){
        return 0.4*scale;
    }
private:
    void CameraKeyboard(unsigned char key, int x, int y);
    void CameraMouseClick(int btu, int state, int x, int y);
    void CameraMotion(int x, int y);
<<<<<<< HEAD
    void shaderTestCurb(VP& TestCurbPoint, int SmallMap);
=======
    void shaderTestCurb(VP& TestCurbPoint);
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
private:
    double TestCurbX,TestCurbY,TestCurbZ;   //测试立方体坐标
    double angleY, angleZ, CameraDistance;  //相机旋转角度与位置
    bool LMouseDown, RMouseDown;            //鼠标左键按下
    int LMouseDownX, LMouseDownY;           //鼠标右键按下的鼠标的位置
    int LCurrentMouseX,LCurrentMouseY;      //鼠标右键按下时当前鼠标的位置
    UINT DealyTime;                         //鼠标拖动旋转停歇时间
    bool EnableCameraDistance;              //是否启用第一人称
    double EnableCameraLastDistance;        //第1人称是的相机距离
    VP TestCurbPoint, TestCurbShaderPoint;                       //测试立方体
    UINT TestCurbShaderID;                  //测试立方体渲染ID
<<<<<<< HEAD
    double scale;                           //测试立方体的缩放
=======
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    //测试立方体点集信息
    const float TestCurb[8][3] = 
    { 
        0.0f, 0.0f, 0.0f,  //0
        0.4f, 0.0f, 0.0f,  //1
        0.4f, 0.0f, -0.4f, //2
        0.0f, 0.0f, -0.4f, //3
        0.0f, 0.4f, 0.0f,  //4
        0.4f, 0.4f, 0.0f,  //5
        0.4f, 0.4f, -0.4f, //6
        0.0f, 0.4f, -0.4f  //7
    }; 

    //测试立方体连接线段
    const GLint TestCurbList[12][2] = 
    { 
        {0, 1},    
        {3, 2},    
        {7, 6},    
        {4, 5},    
        {0, 3},    
        {1, 2},    
        {5, 6},    
        {4, 7},
        {0, 4},
        {1, 5},
        {7, 3},
        {2, 6}
    };

    
};
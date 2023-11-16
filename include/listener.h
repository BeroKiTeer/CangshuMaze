#pragma once
/**
 * keyboardListener 
 * mouseListener
 */
#include <vector>
#include <GL/glut.h>
#include "config.h"
#include "shareddata.h"
extern bool IsThirdPeople;
class Listener {
public:
    Listener();
    ~Listener() = default;

    static bool moveForward;
    static bool moveBack;
    static bool moveLeft;
    static bool moveRight;
    static bool turnLeft;
    static bool turnRight;
    static bool zoomIn;
    static bool zoomOut;

    //getter
    inline bool get_moveForward() const { return moveForward; }
    inline bool get_moveBack() const { return moveBack; }
    inline bool get_moveLeft() const { return moveLeft; }
    inline bool get_moveRight() const { return moveRight; }
    inline bool get_turnLeft() const { return turnLeft; }
    inline bool get_turnRight() const { return turnRight; }
    inline bool get_zoomIn() const { return zoomIn; }
    inline bool get_zoomOut() const { return zoomOut; }
    inline bool get_LMouseDown() const { return LMouseDown; }
    inline bool get_RMouseDown() const { return RMouseDown; }
    inline int get_LMouseDownX() const { return LMouseDownX; }
    inline int get_LMouseDownY() const { return LMouseDownY; }
    inline int get_LCurrentMouseX() const { return LCurrentMouseX; }
    inline int get_LCurrentMouseY() const { return LCurrentMouseY; }
    inline GLuint get_DealyTime() const { return DealyTime; }
    inline bool get_EnableCameraDistance() const { return EnableCameraDistance; }
    inline double get_EnableCameraLastDistance() const { return EnableCameraLastDistance; }
    inline double get_angleY() const { return angleY; }
    inline double get_angleZ() const { return angleZ; }
    inline double get_CameraDistance() const { return CameraDistance; }
    inline double get_TestCurbX() const { return TestCurbX; }
    inline double get_TestCurbY() const { return TestCurbY; }
    inline double get_TestCurbZ() const { return TestCurbZ; }
    inline std::vector<Point> get_TestCurbPoint() const { return TestCurbPoint; }
    inline std::vector<Point> get_TestCurbShaderPoint() const { return TestCurbShaderPoint; }
    inline UINT get_TestCurbShaderID() const { return TestCurbShaderID; }
    inline double get_scale() const { return scale; }



    //setter
    void set_moveForward(const bool &moveForward) {
        this->moveForward = moveForward; 
    }
    void set_moveBack(const bool &moveBack) {
        this->moveBack = moveBack; 
    }
    void set_moveLeft(const bool &moveLeft) {
        this->moveLeft = moveLeft; 
    }
    void set_moveRight(const bool &moveRight) {
        this->moveRight = moveRight; 
    }
    void set_turnLeft(const bool &turnLeft) {
        this->turnLeft = turnLeft; 
    }
    void set_turnRight(const bool &turnRight) {
        this->turnRight = turnRight; 
    }
    void set_zoomIn(const bool &zoomIn) {
        this->zoomIn = zoomIn; 
    }
    void set_zoomOut(const bool &zoomOut) {
        this->zoomOut = zoomOut; 
    }
    void set_LMouseDown(const bool &LMouseDown) {
        this->LMouseDown = LMouseDown; 
    }
    void set_RMouseDown(const bool &RMouseDown) {
        this->RMouseDown = RMouseDown; 
    }
    void set_LMouseDownX(const int &LMouseDownX) {
        this->LMouseDownX = LMouseDownX; 
    }
    void set_LMouseDownY(const int &LMouseDownY) {
        this->LMouseDownY = LMouseDownY; 
    }
    void set_LCurrentMouseX(const int &LCurrentMouseX) {
        this->LCurrentMouseX = LCurrentMouseX; 
    }
    void set_LCurrentMouseY(const int &LCurrentMouseY) {
        this->LCurrentMouseY = LCurrentMouseY; 
    }
    void set_DealyTime(const GLuint &DealyTime) {
        this->DealyTime = DealyTime; 
    }
    void set_EnableCameraDistance(const bool &EnableCameraDistance) {
        this->EnableCameraDistance = EnableCameraDistance; 
    }
    void set_EnableCameraLastDistance(const double &EnableCameraLastDistance) {
        this->EnableCameraLastDistance = EnableCameraLastDistance; 
    }
    void set_angleY(const double &angleY) {
        this->angleY = angleY; 
    }
    void set_angleZ(const double &angleZ) {
        this->angleZ = angleZ; 
    }
    void set_CameraDistance(const double &CameraDistance) {
        this->CameraDistance = CameraDistance; 
    }
    void set_TestCurbX(const double &TestCurbX) {
        this->TestCurbX = TestCurbX; 
    }
    void set_TestCurbY(const double &TestCurbY) {
        this->TestCurbY = TestCurbY; 
    }
    void set_TestCurbZ(const double &TestCurbZ) {
        this->TestCurbZ = TestCurbZ; 
    }
    void set_TestCurbPoint(const std::vector<Point> &TestCurbPoint) {
        this->TestCurbPoint = TestCurbPoint; 
    }
    void set_TestCurbShaderPoint(const std::vector<Point> &TestCurbShaderPoint) {
        this->TestCurbShaderPoint = TestCurbShaderPoint; 
    }
    void set_TestCurbShaderID(const UINT &TestCurbShaderID) {
        this->TestCurbShaderID = TestCurbShaderID; 
    }
    void set_scale(const double &scale) {
        this->scale = scale; 
    }



    //下面是OpenGL的回调函数
    //
    static void mouseClick(int button, int state, int x, int y);
    //button：表示用户按下或释放的鼠标按钮，通常为常量，如 GLUT_LEFT_BUTTON、GLUT_RIGHT_BUTTON 等。
    //state：表示按钮的状态，通常为 GLUT_DOWN（按下）或 GLUT_UP（释放）
    //x,y表示鼠标点击事件发生的窗口内的坐标位置。
    static void mouseMotionListener(int x, int y);
    static void mousePassiveMotionListener(int x, int y);
    //x 和 y：表示鼠标当前的坐标位置。
    static void mouseInMove(int x,int y);
    //x：表示鼠标当前的水平坐标位置，y：表示鼠标当前的垂直坐标位置
    static void keyBoardsListener(unsigned char key, int x, int y);
    //key：表示用户按下的键的ASCII字符。x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    static void keyboardUpListener(unsigned char key,int x,int y);

    static void specialListener(int key, int x, int y);
    //key：表示用户按下的特殊键，通常为常量，如方向键（GLUT_KEY_LEFT、GLUT_KEY_RIGHT等）。
    //x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    static void specialUpListener(int key, int x, int y);
    //key：表示用户释放的特殊键，通常为常量，如方向键（GLUT_KEY_LEFT、GLUT_KEY_RIGHT等）。
    //x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    static void windowFoucusListener(int state);
    //state：表示窗口获取或失去焦点的状态，GLUT_LEFT（失去焦点）或 GLUT_ENTERED（获取焦点）。

private:
    bool LMouseDown;
    bool RMouseDown; 
    int LMouseDownX, LMouseDownY;
    int LCurrentMouseX,LCurrentMouseY; 
    GLuint DealyTime; 
    bool EnableCameraDistance; 
    double EnableCameraLastDistance;
    double angleY, angleZ, CameraDistance; 

    double TestCurbX,TestCurbY,TestCurbZ; 
    std::vector<Point> TestCurbPoint;
    std::vector<Point> TestCurbShaderPoint;  
    UINT TestCurbShaderID;          
    double scale;                       
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
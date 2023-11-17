#include "listener.h"

bool Listener::moveForward = false;
bool Listener::moveBack = false;
bool Listener::moveLeft = false;
bool Listener::moveRight = false;
bool Listener::turnLeft = false;
bool Listener::turnRight = false;
bool Listener::zoomIn = false;
bool Listener::zoomOut = false;
bool Listener::LMouseDown = false;
bool Listener::RMouseDown = false; 
int Listener::LMouseDownX = false;
int Listener::LMouseDownY = false;
int Listener::LCurrentMouseX = 0;
int Listener::LCurrentMouseY = 0; 
GLuint Listener::DealyTime = 0; 
bool Listener::EnableCameraDistance = true; 
double Listener::EnableCameraLastDistance = 1.0;
double Listener::angleY = 15.0;
double Listener::angleZ = -90.0; 
double Listener::CameraDistance = 1.0;

Listener::Listener()
{
    moveForward = false;
    moveForward = false;
    moveBack = false;
    moveLeft = false;
    moveRight = false;
    turnLeft = false;
    turnRight = false;
    LMouseDown = false;                        //鼠标左键按下
    RMouseDown = false;                        //鼠标右键按下
    LMouseDownX = 0;LMouseDownY = 0;           //鼠标右键按下的鼠标的位置
    LCurrentMouseX = 0,LCurrentMouseY = 0;     //鼠标右键按下时当前鼠标的位置
    DealyTime = 0;                      //鼠标拖动旋转停歇时间
    EnableCameraDistance = false;         //是否启用第一人称
    EnableCameraLastDistance = 10;           //第1人称是的相机距离
    TestCurbX=0;
    TestCurbY=0;
    TestCurbZ=0; 
    TestCurbPoint.clear();
    TestCurbShaderPoint.clear();  
    TestCurbShaderID = TextureWallID;          
    scale = 0.4;    
}


void Listener::keyBoardsListener(unsigned char key, int x, int y){
    switch(key){
        case 'w':moveForward = true;break;
        case 's':moveBack = true;break;
        case 'a':moveLeft = true;break;
        case 'd':moveRight = true;break;
        case 'q':turnLeft = true;break;
        case 'e':turnRight = true;break;
        case '1':IsThirdPeople = false;break;
        case '3':IsThirdPeople = true;break;
        default: break;
    }
}
void Listener::keyboardUpListener(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w': moveForward = false; break;
        case 's': moveBack = false; break;
        case 'a': moveLeft = false; break;
        case 'd': moveRight = false; break;
        case 'q': turnLeft = false; break;
        case 'e': turnRight = false; break;
        default: break;
    }
}

void Listener::specialListener(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT: turnLeft = true;break;
        case GLUT_KEY_RIGHT: turnRight = true;break;
        case GLUT_KEY_UP: zoomIn = true; break;
        case GLUT_KEY_DOWN: zoomOut = true; break;
        default:break;
    }
}

void Listener::specialUpListener(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT: turnLeft = false;break;
        case GLUT_KEY_RIGHT: turnRight = false;break;
        case GLUT_KEY_UP: zoomIn = false; break;
        case GLUT_KEY_DOWN: zoomOut = false; break;
        default:break;
    }
}

void Listener::mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_WHEEL_UP){
        if(EnableCameraDistance && CameraDistance > 0.15)
            CameraDistance -= 0.1;
    }
    if(button == GLUT_WHEEL_DOWN && EnableCameraDistance) {
        CameraDistance += 0.1;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        LMouseDown = true;
        LMouseDownX = x, LMouseDownY = y;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        LMouseDown = false;
        DealyTime = 0;
        LMouseDownX = 0, LMouseDownY = 0;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        RMouseDown = true;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        RMouseDown = false;
    }
    // Camera::OCameraMouseClick(button,state,x,y);
}
void Listener::mouseMotionListener(int x, int y){
    if(LMouseDown) {
        double dx = LMouseDownX - x;
        double dy = LMouseDownY - y;
        angleY = angleY - dy/10;
        angleZ = angleZ + dx/10;
        LMouseDownX = x;
        LMouseDownY = y;
    }
}

#include "world.h"
#include "camera.h"
#include "listener.h"
#include "config.h"
#include "shareddata.h"
#include "sky.h"
#include "randomwall.h"
#include "smallmap.h"

extern bool IsThirdPeople;
extern RandomWallXOY wall;

UINT TestCurbShaderID = 0;
void renderScene()
{
    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //=====================================================================================
    glViewport(0,0,WindowsWidth,WindowsHeight);
    //区域1，主地图

    //初始化相机，尽量不动下面两行代码位置
    Camera cameraclass;
    //相机函数必须使用getInstance()之后才能调用其他函数
    cameraclass.getInstance()->Init();

    //模型设置
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    if(IsThirdPeople){
        cameraclass.getInstance()->DisableFirstPerson();
        cameraclass.getInstance()->ShowTestCurb(1);
    }
    else{
        cameraclass.getInstance()->EnableFirstPerson();
        cameraclass.getInstance()->ShowCamera();
    }

    static SkyBox sky;
    sky.ShowSky();

    static World DrawWorld;
    DrawWorld.DrawTestMaze(1);
    DrawWorld.DrawCoordinate();

    glPopMatrix();

    //=====================================================================================
    glViewport(WindowsWidth, 0, SmallMapSizeINT, SmallMapSizeINT);
    //区域2，小地图
    Point2d TestCurbPos= cameraclass.getInstance()->getTestCurbPos2D();
    double TestCurbLong = cameraclass.getInstance()->getTestCurbLong();
    SmallMap::DrawMap(wall,TestCurbPos,TestCurbLong);

    //=====================================================================================
    glViewport(WindowsWidth, WindowsHeight - SmallMapSizeINT, SmallMapSizeINT, SmallMapSizeINT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 0, 0, 10, 10, -10);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    cameraclass.getInstance()->ShowTestCurb(-1);
    DrawWorld.DrawTestMaze(-1);

    glPopMatrix();

    glutSwapBuffers();
    Sleep(10);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth+SmallMapSizeINT,WindowsHeight);
    glutCreateWindow("OpenGL-Experiment");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    //事件监听器
    glutKeyboardFunc(Listener::keyBoardsListener);
    glutMouseFunc(Listener::mouseClick);
    glutMotionFunc(Listener::mouseMotionListener);

    // glutIdleFunc(LookMaze);
    glutMainLoop();

    return 0;
}
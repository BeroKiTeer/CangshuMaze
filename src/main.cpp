#include "world.h"
#include "camera.h"
#include "listener.h"
#include "config.h"
#include "shareddata.h"
#include "sky.h"
<<<<<<< HEAD
#include "randomwall.h"
#include "smallmap.h"

extern bool IsThirdPeople;
extern RandomWallXOY wall;

UINT TestCurbShaderID = 0;
=======
#include "Person.h"
#include "cube.h"
extern bool IsThirdPeople;
UINT TestCurbShaderID = 0;
// static Person person;

>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
void renderScene()
{
    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
<<<<<<< HEAD

    //=====================================================================================
    glViewport(0,0,WindowsWidth,WindowsHeight);
    //区域1，主地图

=======
    
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    //初始化相机，尽量不动下面两行代码位置
    Camera cameraclass;
    //相机函数必须使用getInstance()之后才能调用其他函数
    cameraclass.getInstance()->Init();

    //模型设置
    glMatrixMode(GL_MODELVIEW);
<<<<<<< HEAD
=======
    glLoadIdentity();
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    glPushMatrix();
    glLoadIdentity();
    
    if(IsThirdPeople){
<<<<<<< HEAD
        cameraclass.getInstance()->DisableFirstPerson();
        cameraclass.getInstance()->ShowTestCurb(1);
=======
        
        cameraclass.getInstance()->DisableFirstPerson();
        cameraclass.getInstance()->ShowTestCurb();
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    }
    else{
        cameraclass.getInstance()->EnableFirstPerson();
        cameraclass.getInstance()->ShowCamera();
    }

<<<<<<< HEAD
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
=======


    static SkyBox sky;
    sky.ShowSky();
    
    static World DrawWorld;
    DrawWorld.DrawCoordinate();
    DrawWorld.DrawTestMaze();

    // Cylinder *testCylinder = new Cylinder(Point(2,2,0),0.05,0.5,50);
    // testCylinder->render();
    // delete testCylinder;

    Cube *testcube = new Cube(0.05,0.05,-0.05);
    testcube->render(0.1,0.1,-0.05);
    delete testcube;

    // Ball *testBall = new Ball(Point(0.05,0.05,0.05),0.05,50,50);
    // testBall->render();
    // delete testBall;

    glPopMatrix();
    glutSwapBuffers();
    Sleep(20);
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
}

int main(int argc, char **argv)
{
<<<<<<< HEAD

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth+SmallMapSizeINT,WindowsHeight);
=======
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth,WindowsHeight);
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    glutCreateWindow("OpenGL-Experiment");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

<<<<<<< HEAD
    //事件监听器
=======
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    glutKeyboardFunc(Listener::keyBoardsListener);
    glutMouseFunc(Listener::mouseClick);
    glutMotionFunc(Listener::mouseMotionListener);

<<<<<<< HEAD
    // glutIdleFunc(LookMaze);
    glutMainLoop();

=======
    glutMainLoop();
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    return 0;
}
#include "world.h"
#include "camera.h"
#include "listener.h"
#include "config.h"
#include "shareddata.h"
#include "sky.h"
extern bool IsThirdPeople;
UINT TestCurbShaderID = 0;
void renderScene()
{
    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //初始化相机，尽量不动下面两行代码位置
    Camera cameraclass;
    //相机函数必须使用getInstance()之后才能调用其他函数
    cameraclass.getInstance()->Init();

    //模型设置
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    
    if(IsThirdPeople){
        cameraclass.getInstance()->DisableFirstPerson();
        cameraclass.getInstance()->ShowTestCurb();
    }
    else{
        cameraclass.getInstance()->EnableFirstPerson();
        cameraclass.getInstance()->ShowCamera();
    }

    static SkyBox sky;
    sky.ShowSky();

    static World DrawWorld;
    DrawWorld.DrawCoordinate();
    DrawWorld.DrawTestMaze();

    glPopMatrix();
    glutSwapBuffers();
    Sleep(10);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth,WindowsHeight);
    glutCreateWindow("OpenGL-Experiment");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    glutKeyboardFunc(Listener::keyBoardsListener);
    glutMouseFunc(Listener::mouseClick);
    glutMotionFunc(Listener::mouseMotionListener);

    glutMainLoop();
    return 0;
}
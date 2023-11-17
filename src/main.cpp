#include "world.h"
#include "camera.h"
#include "listener.h"
#include "config.h"
#include "shareddata.h"
#include "sky.h"
#include "Person.h"
#include "cube.h"
#include "randomwall.h"
#include "smallmap.h"
#include "cube.h"

extern bool IsThirdPeople;
extern RandomWallXOY wall;

extern GLuint TextureWallID;
extern GLuint TextureFloorID;
extern GLuint TextureTextcurbID;

GLuint SCENESPEED = 20;
GLuint SCENEID = 0;

UINT TestCurbShaderID = 0;

Camera cameraclass;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //加载渲染
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 

    if(TextureWallID == 0)
        TextureWallID = loadTexture("texture/wall.bmp");
    if(TextureFloorID == 0)
        TextureFloorID = loadTexture("texture/floor.bmp");
    if(TextureTextcurbID == 0)
        TextureTextcurbID == loadTexture("texture/TestCurb.bmp");

    if(!TextureWallID && !TextureFloorID && !TextureTextcurbID){
        std::cout << "Load Picture failed" << std::endl;
        exit(0);
    }

    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D);

    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //=====================================================================================
    glViewport(0,0,WindowsWidth,WindowsHeight);
    cameraclass.getInstance()->Init();
    //模型设置
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    
    if(IsThirdPeople){
        cameraclass.DisableFirstPerson();
        cameraclass.ShowTestCurb(1);
    }
    else{
        cameraclass.EnableFirstPerson();
        cameraclass.ShowCamera();
    }

    
    static SkyBox sky;
    sky.ShowSky(); 

    

    static World DrawWorld;
    DrawWorld.DrawTestMaze(1);
    DrawWorld.DrawCoordinate();

    Person *person = new Person();
    delete person;

    // Ball *ball = new Ball(Point(0.1,0.1,-0.1),0.05,50,50);
    // ball->render();
    // delete ball;

    // Cylinder *cylinder = new Cylinder(Point(0.2,0.2,-0.1),0.01,0.1,50);
    // cylinder->render();
    // delete cylinder;

    // Cube cube1(1.0, 1.0, 0.0, 3.0, 0.25, 0.5);
    // cube1.render_wall(1);
    vector<Cube> WallGroup;
    for(auto i : wall.VWall){
        WallGroup.push_back(Cube(i.DrawX, i.DrawY, 0.0, i.LongX, i.LongY, 0.5));
    }

    for(auto i : WallGroup){
        i.render_wall(1);
    }

    glPopMatrix();

    //=====================================================================================
    glViewport(WindowsWidth, 0, SmallMapSizeINT, SmallMapSizeINT);

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

    for(auto i : WallGroup){
        i.render_wall(-1);
    }

    glPopMatrix();

    glutSwapBuffers();
}

void sceneMoveLoop(int id)
{
    if (cameraclass.moveForward) {
        cameraclass.set_TestCurbY(cameraclass.get_TestCurbY()+0.05);
        std::cout << cameraclass.get_TestCurbY() << std::endl;
        // std::cout << Listener::get_TestCur) << std::endl;
    }
    if (cameraclass.moveBack) {
        cameraclass.set_TestCurbY(cameraclass.get_TestCurbY()-0.05);
        std::cout << cameraclass.get_TestCurbY() << std::endl;
    }
    if (cameraclass.moveLeft) {
        cameraclass.set_TestCurbX(cameraclass.get_TestCurbX()+0.05);
    }
    if (cameraclass.moveBack) {
        cameraclass.set_TestCurbX(cameraclass.get_TestCurbX()-0.05);
    }

    glutPostRedisplay();
    glutTimerFunc(SCENESPEED, sceneMoveLoop, id);
}

int main(int argc, char **argv)
{
    wall.RandomWall();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth+SmallMapSizeINT,WindowsHeight);
    glutCreateWindow("MazeGame");

    glutDisplayFunc(display);
    // glutIdleFunc(display);

    //listener
    glutKeyboardFunc(Listener::keyBoardsListener);
    glutKeyboardUpFunc(Listener::keyboardUpListener);
    glutMouseFunc(Listener::mouseClick);
    glutMotionFunc(Listener::mouseMotionListener);
    glutSpecialFunc(Listener::specialListener);
    glutSpecialUpFunc(Listener::specialUpListener);

    //loop
    glutTimerFunc(SCENESPEED, sceneMoveLoop, SCENEID);
    glutMainLoop();

    return 0;
}


// int main (int argc, char** argv)
// {
//     std::cout << "Hello,world" << std::endl;

//     //����
//     glutInit(&argc,argv);
//     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//     glutInitWindowSize(W, H); 
//     glutInitWindowPosition(0, 0);
//     glutCreateWindow("Maze");

//     //��ʼ��������������ͼ����ʼ�������ǽ���ذ��Ԫ�أ�������ͼ
    

//     //��Ⱦ
//     glEnable(GL_TEXTURE_2D);
//     glutDisplayFunc([](){
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         glDisable(GL_DEPTH_TEST);       //�ر���Ȳ��ԣ�����ֹOpenGL���������Ƚ��м�⡣�����ڻ���һЩ����Ҫ�������Ķ���ʱʹ�õġ�
//         glLoadIdentity();   //���õ�ǰģ����ͼ����Ϊ��λ����
//         /*
//         glRotated(obvRotateY, 1, 0, 0);
//         glRotated(obvRotateX, 0, 1, 0);
//         */
//         //�ֱ��X���Y�������ת�����ڵ����ӽǻ�����ķ���
//         //addSky();��Ⱦ��պ�

//         glEnable(GL_DEPTH_TEST);    //����������Ȳ��ԣ���ȷ����Ⱦ������������ǵ����λ����ȷ����
//         glLoadIdentity();
//         glLineWidth(3);
//         //updateObverse();����OpenGL�Ĺ۲��ӽǣ���ͼ����
//         //addGround();  ��Ⱦ����
//         //addWall();    ��Ⱦǽ
//         //addActor();   ��Ⱦ��ɫ��Person��

//         // drawLine(-300, 0, 0, 300, 0, 0, WHITE);
//         // drawLine(0, -300, 0, 0, 300, 0, WHITE);
//         // drawLine(0, 0, -300, 0, 0, 300, WHITE);
//         glutSwapBuffers();  //����ǰ�󻺳���������ʾ���µ���Ⱦ������Ӷ����һ֡����Ⱦ��
//     }); 
//     glutReshapeFunc([](int w,int h){//�ı䴰�ڴ�Сʱ����ͼ�α���
//         glViewport(0, 0, w, h);     
//         //������OpenGL���ӿڣ�����OpenGL�����Ƶ������޶��ڴ��ڵ����½ǣ�0,0�������Ͻǣ�w,h��������w �� h ���´��ڵĿ��Ⱥ͸߶�
//         glMatrixMode(GL_PROJECTION);    //��OpenGL�ľ���ģʽ�л�ΪͶӰ����ģʽ
//         glLoadIdentity();               //��һ�н���ǰ����ͶӰ��������Ϊ��λ����

//         gluPerspective(60, (double)w/h, 0.1, 500);//���߱ȸ�Ϊ��ǰֵ��������������Ļ��Сһ�£�

//         // if (openMap) {      //����ͶӰ
//         //     glOrtho(-GZ*mapViewFac*w/h/F, GZ*mapViewFac*w/h/F,
//         //     -GZ*mapViewFac/F, GZ*mapViewFac/F, 0.1, siteDistance);
//         // } else {            //͸��ͶӰ
//         //     gluPerspective(60, (double)w/h, 0.1, siteDistance);
//         // }



//         glMatrixMode(GL_MODELVIEW);     //��OpenGL�ľ���ģʽ�л���ģ����ͼ����ģʽ
//         glLoadIdentity();     //�ٴν���ǰ����ģ����ͼ��������Ϊ��λ������ȷ��ģ����ͼ����ĳ�ʼ״̬
//         W = w, H = h;
//     });

//     //listener


//     //loop
//     /*
//     glutTimerFunc(SCENESPEED, sceneMoveLoop, SCENEID);  //�����������ƶ������
//     glutTimerFunc(ACTROTATESPEED, actRotateLoop, ACTROTATEID);      //������ɫ��������ת����
//     glutTimerFunc(ACTORJUMPSPEED, actJumpLoop, ACTORJUMPID);        //�ڴ�����ɫ��������Ծ����
//     */
//     glutMainLoop();

//     return 0;
// }

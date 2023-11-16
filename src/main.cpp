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

UINT TestCurbShaderID = 0;
void renderScene()
{
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

    Camera cameraclass;
    //�����������ʹ��getInstance()֮����ܵ�����������
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
    Sleep(10);
}

void sceneMoveLoop(int id)
{
    // person->move()
    // person->draw();

    glutPostRedisplay();
    // glutTimerFunc(SCENESPEED, sceneMoveLoop, id);
}

int main(int argc, char **argv)
{
    wall.RandomWall();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowsWidth+SmallMapSizeINT,WindowsHeight);
    glutCreateWindow("MazeGame");

    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    //事件监听�?
    glutKeyboardFunc(Listener::keyBoardsListener);
    glutMouseFunc(Listener::mouseClick);
    glutMotionFunc(Listener::mouseMotionListener);

    //loop
    // glutTimerFunc(SCENESPEED, sceneMoveLoop, SCENEID);
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

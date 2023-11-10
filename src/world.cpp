#include "world.h"

World::World()
{
    angleX = 0.0; angleY = 0.0; CameraDistance = 0.3;
    x = 0.1; y = 0.2; z = 1.5;
    for(int i = 0; i < 8; i++){
        TestCurbPoint.push_back(Point(TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]));
    }
    for(int i = 0; i < 4; i++){
        CoordinatePoint.push_back(Point(coordinate[i][0],coordinate[i][1],coordinate[i][2]));
    }
}

void World::ShowWorld(int argc, char **argv, GLuint width, GLuint Height)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(width, Height);
    glutCreateWindow("OpenGL-Experiment");

    glutDisplayFunc(World::Test);
    glutIdleFunc(World::Test);

    glutKeyboardFunc(World::Test2);
    glutMainLoop();
}

void World::CreateMazeBox()
{
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    if(flood == 0){
        flood = loadTexture("texture/floor.bmp");
        if(flood == 0){
            std::cerr << "图片加载失败" << std::endl;
            exit(0);
        }
    }
    if(wall == 0){
        wall = loadTexture("texture/wall.bmp");
        if(wall == 0){
            std::cerr << "图片加载失败" << std::endl;
            exit(0);
        }
    }
    //画地板
    glBindTexture(GL_TEXTURE_2D, flood);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(0.0f, 0.0f, 5.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(5.0f, 0.0f, 5.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
	glEnd();
    //画墙板
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(5.0f, 0.5f, 0.0f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.5f, 0.0f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(0.0f, 0.5f, 5.0f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 5.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.5f, 5.0f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(5.0f, 0.5f, 5.0f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f, 0.5f, 0.0f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(5.0f, 0.5f, 5.0f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(5.0f, 0.0f, 5.0f);
	glEnd();
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}

void World::DrawCoordinate(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    for(int i=0; i<3; ++i)
    {
        if(i == 1)
            glColor3f(0.0f,1.0f,0.0f);
        if(i == 2)
            glColor3f(0.0f,0.0f,1.0f);
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = CoordinatePoint[coordinateList[i][j]].x;
            GLfloat y = CoordinatePoint[coordinateList[i][j]].y;
            GLfloat z = CoordinatePoint[coordinateList[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

void World::DrawCube(){
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<12; ++i) // 12 条线段
    {
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = TestCurbPoint[TestCurbList[i][j]].x;
            GLfloat y = TestCurbPoint[TestCurbList[i][j]].y;
            GLfloat z = TestCurbPoint[TestCurbList[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

void World::SetCamera(
    double x, double y, double z, double CameraDistance,
    double LookX, double LookY, double LookZ,
    double angleX, double angleY)
{
    VP CameraPoint;
    CameraPoint.push_back(Point(x,y,z+CameraDistance));
    //绕立方体旋转,绕y轴旋转 T1*T2*T1^(-1)

    translate(CameraPoint,-x,-y,-z);
    //先旋转x后旋转y，矩阵不满足交换律
    rotateDX(CameraPoint,angleX);
    rotateDY(CameraPoint,angleY);
    translate(CameraPoint,x,y,z);

    //设置视点
    gluLookAt (
        CameraPoint[0].x, CameraPoint[0].y, CameraPoint[0].z, //相机位置
        LookX, LookY, LookZ, //立方体所在的点                  //观察点位置
        0.0, 1.0, 0.0);      //定值  
}

void World::renderScene()
{
    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //设置透视投影
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100.0); // 透视投影
    glPushMatrix();

    //模型处理
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // //缩放立方体和
    scaleEntirety(TestCurbPoint,0.25);
    scaleEntirety(TestCurbPoint,0.0675);
    // //平移立方体
    translate(TestCurbPoint,x, y, z);
    std::cout << x << " " << y << " " << z << std::endl;
    // //设置相机
    SetCamera(x, y, z,CameraDistance,
              x, y, z,angleX, angleY);

    // //开始绘制所有
    CreateMazeBox();

    DrawCoordinate();
    DrawCube();

    ResetCoordinatePoint();
    ResetTestCurb();

    glPopMatrix();
    glutSwapBuffers();
    Sleep(10);
}

void World::KeyBoards(unsigned char key,int x,int y){
switch (key)
	{
        //变换
        case 'w':
            z -= 0.1;break;
        case 's':
            z += 0.1;break;
        case 'a':
            this->x -= 0.1;
            std::cout << x << std::endl;
            break;
        case 'd':
            this->x += 0.1;break;
        case 'q':
            this->y += 0.1;break;
        case 'e':
            this->y -= 0.1;break;
        case 'z':
            angleX += 1.0;break;
        case 'x':
            angleX -= 1.0;break;
        case 'c':
            angleY += 1.0;break;
        case 'v':
            angleY -= 1.0;break;
        case 'b':
            CameraDistance += 0.1;break;
        case 'n':
            CameraDistance -= 0.1;break;
        default:
            break;
	}
}
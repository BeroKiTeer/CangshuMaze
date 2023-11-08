#include<GL/glut.h>
#include<iostream>
#include <cmath>
#include "data.h"
#include "transform.h"

using namespace std;
VP Curb1Point, Curb2Point, CoordinatePoint;

// 键盘事件响应
void KeyBoards(unsigned char key,int x1,int y1)
{
	switch (key)
	{
        case '1':
            ++x_;break;
        case '2':
            ++y_;break;
        case '3':
            ++z_;break;
        case '4':
            --x_;break;
        case '5':
            --y_;break;
        case '6':
            --z_;break;
        case 'q':
            x2 += 0.1;break;
        case 'w':
            y2 += 0.1;break;
        case 'e':
            z2 += 0.1;break;
        case 'a':
            x2 -= 0.1;break;
        case 's':
            y2 -= 0.1;break;
        case 'd':
            z2 -= 0.1;break;
        // case '-':
        //     d += 0.1;break;
        // case '=':
        //     d -= 0.1;break;
        default:
            break;
	}
}

// 绘制立方体
void DrawCube(const VP& Point,const GLint v_list[][2])
{
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<12; ++i) // 12 条线段
    {
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = Point[v_list[i][j]].x;
            GLfloat y = Point[v_list[i][j]].y;
            GLfloat z = Point[v_list[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

// 绘制棱锥
void DrawCube2(const VP& Point,const GLint v_list[][2])
{
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<8; ++i) // 12 条线段
    {
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = Point[v_list[i][j]].x;
            GLfloat y = Point[v_list[i][j]].y;
            GLfloat z = Point[v_list[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

//绘制坐标系，R, G, B == X轴, Y轴, Z轴
void DrawCoordinate(const VP& Point,const GLint v_list[][2]){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    for(int i=0; i<8; ++i)
    {
        if(i == 2)
            glColor3f(0.0f,1.0f,0.0f);
        if(i == 4)
            glColor3f(0.0f,0.0f,1.0f);
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = Point[v_list[i][j]].x;
            GLfloat y = Point[v_list[i][j]].y;
            GLfloat z = Point[v_list[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

// 绘制俯视图
void DrawLine(const VP2& Point,const GLint v_list[][2])
{
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<Point.size(); ++i) 
    {
        for(int j=0; j<2; ++j) 
        {
            GLfloat x = Point[v_list[i][j]].x;
            GLfloat y = Point[v_list[i][j]].y;
            glVertex2f(x,y); 
        }
    }
    glEnd();
}


void renderScene(void)
{
    static double angle = 0; //角度变换

    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glPushMatrix();

    //！！！这是OpenGL的全局坐标系旋转，和投影平面有直接关系
    //目的是: 观察变换
    glRotated(0, 0.0, 1.0, 0.0);
    glRotated(240, 1.0, 0.0, 0.0);
    glRotated(30, 0.0, 0.0, 1.0);
    
    //绘制坐标系
    DrawCoordinate(CoordinatePoint,coordinate_list);

    //每10ms增加一个角度
    if(angle > 360)
        angle = 0;
    ++angle;
    // rotateDX(Curb1Point,angle); //X轴旋转
    // rotateDY(Curb1Point,angle); //Y轴旋转
    // rotateDZ(Curb1Point,angle); //Z轴旋转

    // q w e 增加 x轴 y轴 z轴缩放
    // a s d 减少 x轴 y轴 z轴缩放
    // 之所以都+1.0是因为x2,y2,z2默认都是0.0开始的，缩放0表示没有图形
    // scaleXYZ(Curb1Point,x2+1.0,y2+1.0,z2+1.0);

    // q w e 增加 x轴 y轴 z轴平移
    // a s d 减少 x轴 y轴 z轴平移
    // translate(Curb1Point, x2, y2, z2);

    DrawCube(Curb1Point,curb_list1);
    // 俯视图, 需要注释掉下面这几个语句
        /*
        glRotated(0, 0.0, 1.0, 0.0);
        glRotated(240, 1.0, 0.0, 0.0);
        glRotated(30, 0.0, 0.0, 1.0);
        ...
        DrawCube(Curb1Point,curb_list1);
        */
    // VP2 t = TTop(Curb1Point);
    // DrawLine(t,curb_list1);

    //重置变换后点的信息
    UINT size = Curb1Point.size();
    Curb1Point.clear();
    for(UINT i = 0; i < size; i++){
        Curb1Point.push_back(Point(curb1[i][0],curb1[i][1],curb1[i][2]));
    }

    glPopMatrix();
    glutSwapBuffers();
    Sleep(10);
}

void renderScene2(void)
{
    static double angle2 = 0; //角度变换

    glClearColor((float)(238/255.0), (float)(233/255.0), (float)(233/255.0), 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    glPushMatrix();

    //！！！这是OpenGL的全局坐标系旋转，和投影平面有直接关系
    //目的是: 观察变换
    // glRotated(0, 0.0, 1.0, 0.0);
    // glRotated(240, 1.0, 0.0, 0.0);
    // glRotated(30, 0.0, 0.0, 1.0);
    
    //绘制坐标系
    DrawCoordinate(CoordinatePoint,coordinate_list);

    //每10ms增加一个角度
    if(angle2 > 360)
        angle2 = 0;
    ++angle2;
    // rotateDX(Curb2Point,angle2); //X轴旋转
    // rotateDY(Curb2Point,angle2); //Y轴旋转
    // rotateDZ(Curb2Point,angle2); //Z轴旋转

    // q w e 增加 x轴 y轴 z轴缩放
    // a s d 减少 x轴 y轴 z轴缩放
    // scaleXYZ(Curb2Point,x2+1.0,y2+1.0,z2+1.0);

    // q w e 增加 x轴 y轴 z轴平移
    // a s d 减少 x轴 y轴 z轴平移
    // translate(Curb2Point, x2, y2, z2);

    DrawCube2(Curb2Point,curb_list2);
    // 俯视图, 需要注释掉下面这几个语句
        /*
        glRotated(0, 0.0, 1.0, 0.0);
        glRotated(240, 1.0, 0.0, 0.0);
        glRotated(30, 0.0, 0.0, 1.0);
        ...
        DrawCube(Curb2Point,curb_list2);
        */
    // VP2 t = TTop(Curb2Point);
    // DrawLine(t,curb_list2);

    //重置变换后点的信息
    UINT size = Curb2Point.size();
    Curb2Point.clear();
    for(UINT i = 0; i < size; i++){
        Curb2Point.push_back(Point(curb2[i][0],curb2[i][1],curb2[i][2]));
    }

    glPopMatrix();
    glutSwapBuffers();
    Sleep(10);
}

int main(int argc, char **argv)
{   
    //加载点的信息到VP中，点集信息
    for(int i = 0; i < 8; i++){
        Curb1Point.push_back(Point(curb1[i][0],curb1[i][1],curb1[i][2]));
    }
    for(int i = 0; i < 5; i++){
        Curb2Point.push_back(Point(curb2[i][0],curb2[i][1],curb2[i][2]));
    }
    for(int i = 0; i < 7; i++){
        CoordinatePoint.push_back(Point(coordinate[i][0],coordinate[i][1],coordinate[i][2]));
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLDemo");

    //模型1
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);

    //模型2
    // glutDisplayFunc(renderScene2);
    // glutIdleFunc(renderScene2);

    glutKeyboardFunc(&KeyBoards);
    glutMainLoop();
    return 0;
}


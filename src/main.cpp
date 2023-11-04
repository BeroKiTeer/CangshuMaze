#include "GL/freeglut_std.h"
#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/freeglut.h>
#include "Person.h"

const int W = 800;
const int H = 600;

int main (int argc, char** argv)
{
    std::cout << "Hello,world" << std::endl;

    //窗口
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(W, H); 
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Maze");

    //初始化
    

    //渲染
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc([](){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_DEPTH_TEST);       //关闭深度测试，即禁止OpenGL对物体的深度进行检测。这是在绘制一些不需要深度排序的对象时使用的。
        glLoadIdentity();   //重置当前模型视图矩阵为单位矩阵
        glRotated(obvRotateY, 1, 0, 0);
        glRotated(obvRotateX, 0, 1, 0);
        //分别对X轴和Y轴进行旋转。用于调整视角或相机的方向。
        //addSky();渲染天空盒

        glEnable(GL_DEPTH_TEST);    //重新启用深度测试，以确保渲染的物体根据它们的深度位置正确排序。
        glLoadIdentity();
        glLineWidth(3);
        //updateObverse();
        //addGround();更新OpenGL的观察视角（视图矩阵）
        addWall();
        addActor();

        // drawLine(-300, 0, 0, 300, 0, 0, WHITE);
        // drawLine(0, -300, 0, 0, 300, 0, WHITE);
        // drawLine(0, 0, -300, 0, 0, 300, WHITE);
        glutSwapBuffers();
    }); 
    glutReshapeFunc(reshape);

    return 0;
}
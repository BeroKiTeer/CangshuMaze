#include "GL/freeglut_std.h"
#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/freeglut.h>
#include "Person.h"

int W = 800;
int H = 600;

int main (int argc, char** argv)
{
    std::cout << "Hello,world" << std::endl;

    //窗口
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(W, H); 
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Maze");

    //初始化：加载纹理贴图，初始化相机、墙、地板等元素，建立地图
    

    //渲染
    glEnable(GL_TEXTURE_2D);
    glutDisplayFunc([](){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDisable(GL_DEPTH_TEST);       //关闭深度测试，即禁止OpenGL对物体的深度进行检测。这是在绘制一些不需要深度排序的对象时使用的。
        glLoadIdentity();   //重置当前模型视图矩阵为单位矩阵
        /*
        glRotated(obvRotateY, 1, 0, 0);
        glRotated(obvRotateX, 0, 1, 0);
        */
        //分别对X轴和Y轴进行旋转。用于调整视角或相机的方向。
        //addSky();渲染天空盒

        glEnable(GL_DEPTH_TEST);    //重新启用深度测试，以确保渲染的物体根据它们的深度位置正确排序。
        glLoadIdentity();
        glLineWidth(3);
        //updateObverse();更新OpenGL的观察视角（视图矩阵）
        //addGround();  渲染地面
        //addWall();    渲染墙
        //addActor();   渲染角色（Person）

        // drawLine(-300, 0, 0, 300, 0, 0, WHITE);
        // drawLine(0, -300, 0, 0, 300, 0, WHITE);
        // drawLine(0, 0, -300, 0, 0, 300, WHITE);
        glutSwapBuffers();  //交换前后缓冲区，以显示最新的渲染结果，从而完成一帧的渲染。
    }); 
    glutReshapeFunc([](int w,int h){
        glViewport(0, 0, w, h);     
        //设置了OpenGL的视口，告诉OpenGL将绘制的区域限定在窗口的左下角（0,0）到右上角（w,h）的区域。w 和 h 是新窗口的宽度和高度
        glMatrixMode(GL_PROJECTION);    //将OpenGL的矩阵模式切换为投影矩阵模式
        glLoadIdentity();                      //这一行将当前矩阵（投影矩阵）重置为单位矩阵
        if (openMap) {      //正交投影
            glOrtho(-GZ*mapViewFac*w/h/F, GZ*mapViewFac*w/h/F,
            -GZ*mapViewFac/F, GZ*mapViewFac/F, 0.1, siteDistance);
        } else {            //透视投影
            gluPerspective(60, (double)w/h, 0.1, siteDistance);
        }
        glMatrixMode(GL_MODELVIEW);     //将OpenGL的矩阵模式切换回模型视图矩阵模式
        glLoadIdentity();     //再次将当前矩阵（模型视图矩阵）重置为单位矩阵，以确保模型视图矩阵的初始状态
        W = w, H = h;
    });

    //listener


    //loop
    glutTimerFunc(SCENESPEED, sceneMoveLoop, SCENEID);  //处理场景的移动或更新
    glutTimerFunc(ACTROTATESPEED, actRotateLoop, ACTROTATEID);      //处理角色或对象的旋转动画
    glutTimerFunc(ACTORJUMPSPEED, actJumpLoop, ACTORJUMPID);        //于处理角色或对象的跳跃动画
    glutMainLoop();

    return 0;
}
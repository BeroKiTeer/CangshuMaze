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
    
    return 0;
}
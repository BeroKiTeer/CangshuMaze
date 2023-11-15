#pragma once
#include <GL/gl.h>
#include <vector>
/*
立方体父类，被地板类和墙类继承
*/
class Cube {
public:
    Cube(GLfloat width,GLfloat height,GLfloat depth);
    //要放在的位置

    void render_wall(GLfloat x, GLfloat y, GLfloat z);
    void render_floor(GLfloat x, GLfloat y, GLfloat z);

private:
    GLfloat width = 0.2;   // 长方体宽度
    GLfloat height = 0.2;  // 长方体高度
    GLfloat depth = 0.5;   // 长方体深度
    GLuint texID;
    GLfloat x,y,z;
};
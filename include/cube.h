#pragma once
#include <GL/gl.h>
#include <vector>
/*
立方体父类，被地板类和墙类继承
*/
class Cube {
public:
    Cube(GLfloat width,GLfloat height,GLfloat depth);

    void render(GLfloat x, GLfloat y, GLfloat z);

private:
    GLfloat width;   // 长方体宽度
    GLfloat height;  // 长方体高度
    GLfloat depth;   // 长方体深度
};
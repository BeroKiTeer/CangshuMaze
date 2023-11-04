#pragma once
#include <GL/gl.h>
#include <vector>
/*
立方体父类，被地板类和墙类继承
*/
class Cube {
public:
    Cube(GLfloat width,GLfloat height,GLfloat depth);

    void render();

private:
    float width;   // 长方体宽度
    float height;  // 长方体高度
    float depth;   // 长方体深度
};
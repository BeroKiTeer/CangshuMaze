#pragma once
#include <vector>
#include <GL\gl.h>
#include <GL\glut.h>
#include "config.h"
#include "transform.h"
class Ball {
public:
    Ball() = default;
    Ball(Point P,GLfloat radius, GLint slices,GLint stacks);
    ~Ball() = default;

    void render();

private:
    GLfloat radius;                 //半径
    GLint slices = 30;              //经线数量
    GLint stacks = 30;              //纬线数量
    Point P;                        //球心坐标
};
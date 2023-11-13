#pragma once
#include <vector>
#include <GL\gl.h>
#include <config.h>
class Ball {
public:
    Ball();
    Ball(Point p,GLfloat radius, GLint segments);

    void generateVertices();

    void render();

private:
    GLfloat radius;
    GLint slices = 30;
    GLint stacks = 30;
    Point p;
    std::vector<Point> vertices; // 顶点坐标
};
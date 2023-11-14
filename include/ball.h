#pragma once
#include <vector>
#include <GL\gl.h>
#include "config.h"
class Ball {
public:
    Ball() = default;
    Ball(Point P,GLfloat radius, GLint slices,GLint stacks);

    void generateVertices();

    void render();

private:
    GLfloat radius;
    GLint slices = 30;
    GLint stacks = 30;
    Point P;
    std::vector<Point> vertices;    // 顶点坐标
    std::vector<Point> normals;     // 法向量,与表面垂直的矢量
};
#pragma once
#include <vector>
#include <GL\gl.h>

class Ball {
public:
    Ball();
    Ball(GLfloat radius, GLint segments);

    void render();

private:
    GLfloat radius;
    GLint segments;

    std::vector<GLfloat> vertices; // 顶点坐标
    std::vector<GLfloat> normals;  // 法线
};
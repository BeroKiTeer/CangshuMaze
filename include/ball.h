#pragma once
#include <vector>
#include <GL\gl.h>

class Ball {
public:
    Ball();
    Ball(GLfloat radius, GLint segments);

    void generateVertices();

    void render();

private:
    GLfloat radius;
    GLint slices = 30;
    GLint stacks = 30;

    std::vector<GLfloat> vertices; // 顶点坐标
    std::vector<GLfloat> normals;  // 法线
};
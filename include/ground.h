#pragma once
#include <vector>
#include <string>
#include <gl/gl.h>
#include "config.h"
#include "cube.h"
class Ground : public Cube {
public:
    Ground() = default;
    Ground(GLfloat width,GLfloat height,GLfloat depth);
    ~Ground() = default;

    void init(const std::vector<GLfloat>& vertices, const std::string& texturePath);
    void getGround();
    void addGround();
    void cleanup();

private:
    std::vector<GLfloat> vertices; // 顶点坐标、法线、纹理坐标等数据
    GLuint VAO;     // 顶点数组对象
    GLuint VBO;     // 顶点缓冲对象
    GLuint texture; // 贴图
};
#pragma once
#include <vector>
#include <iostream>
#include <gl/gl.h>
#include "config.h"

class Wall{
public:
    Wall() = default;
    ~Wall() = default;

    void init(const std::vector<GLfloat>& vertices, const std::string& texturePath);
    void getWall();
    void addWall();
    void cleanup();

private:
    std::vector<GLfloat> vertices; // 顶点坐标、法线、纹理坐标等数据
    GLuint VAO;     // 顶点数组对象
    GLuint VBO;     // 顶点缓冲对象
    GLuint texture; // 贴图
};

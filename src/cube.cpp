#include "cube.h"
#include "shader.h"
#include <iostream>
Cube::Cube(GLfloat width, GLfloat height, GLfloat depth):width(width),height(height),depth(depth)
{}

void Cube::render(GLfloat x, GLfloat y, GLfloat z)
{
    /*世界坐标系下显示立方体*/
    // glPushMatrix();
    double cx = (width)/2.0;
    double cy = (depth)/2.0;
    double cz = (height)/2.0;
    if(texID == 0){
        texID = loadTexture("texture/wall.bmp");
        if(texID == 0){
            std::cerr << "图片加载失败" << std::endl;
            exit(0);
        }
    }
    glBindTexture(GL_TEXTURE_2D, texID);
    glBegin(GL_QUADS);
    // 左面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-cx,  cy, -cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-cx,  cy,  cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx, -cy,  cz);
    // 右面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(cx, -cy, -cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(cx,  cy, -cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(cx,  cy,  cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(cx, -cy,  cz);
    // 上面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, cy, -cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f( cx, cy, -cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f( cx, cy,  cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx, cy,  cz);
    // 下面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f( cx, -cy, -cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f( cx, -cy,  cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx, -cy,  cz);
    // 前面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, -cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f( cx, -cy, -cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f( cx,  cy, -cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx,  cy, -cz);
    // 后面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-cx, -cy, cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f( cx, -cy, cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f( cx,  cy, cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-cx,  cy, cz);
    glEnd();
//     glPopMatrix();
}
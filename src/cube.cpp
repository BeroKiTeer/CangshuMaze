#include "cube.h"
#include "shader.h"
#include <iostream>
Cube::Cube(GLfloat width, GLfloat height, GLfloat depth):x(width),y(height),z(depth)
{}

void Cube::render_wall(GLfloat x, GLfloat y, GLfloat z)
{
    /*世界坐标系下显示立方体*/
    // glPushMatrix();
    double cx = width;
    double cy = depth;
    double cz = height;
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
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y, z-cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x, y+cy, z-cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x, y+cy, z);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y, z);
    // 右面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x+cx, y, z-cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x+cx, y+cy, z-cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x+cx, y+cy, z);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x+cx, y,  z);
    // 上面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y+cy, z-cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x+cx, y+cy, z-cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x+cx, y+cy,  z);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y+cy,  z);
    // 下面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y, z-cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x+cx, y, z-cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x+cx, y,  z);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y,  z);
    // 前面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y, z-cz);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x+cx, y, z-cz);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x+cx, y+cy, z-cz);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y+cy, z-cz);
    // 后面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(x+cx, y, z);
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(x+cx, y+cy, z);
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(x, y+cy, z);
    glEnd();
//     glPopMatrix();
}
void render_floor(GLfloat x, GLfloat y, GLfloat z)
{

}
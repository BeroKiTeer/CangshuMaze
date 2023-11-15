#include "cube.h"
#include "shader.h"
#include <iostream>
Cube::Cube(GLfloat width, GLfloat height, GLfloat depth):x(width),y(height),z(depth)
{}

void Cube::render_wall(GLfloat x, GLfloat y, GLfloat z)
{
    /*世界坐标系下显示立方体*/
    // glPushMatrix();
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
    // glColor4f(1.0, 1.0, 1.0,1.0);  // 设置颜色
    
    glBindTexture(GL_TEXTURE_2D, texID);
    glTranslated(x,y,z);
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
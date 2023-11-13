#pragma once
#include <GL/gl.h>
#include <vector>
/*
立方体父类，被地板类和墙类继承
*/
class Cube {
public:
    Cube(GLfloat width,GLfloat height,GLfloat depth);

    void render(GLfloat x, GLfloat y, GLfloat z){
        /*世界坐标系下显示立方体*/
        // glPushMatrix();
        double cx = (x+width)/2.0;
        double cy = (y+depth)/2.0;
        double cz = (z+height)/2.0;
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

private:
    GLfloat width;   // 长方体宽度
    GLfloat height;  // 长方体高度
    GLfloat depth;   // 长方体深度
};
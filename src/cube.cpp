#include "cube.h"

void Cube::render(GLuint id){
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 

    glBindTexture(GL_TEXTURE_2D, id);
    glBegin(GL_QUADS);
    // 左面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y, z);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y, z-Height);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z);
    // 右面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(x*SmallMap, y, z);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y, z-Height);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f(x*SmallMap, y+Width, z);
    // 上面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y, z-Height);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f(x*SmallMap, y, z-Height);
    // 下面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y, z);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y+Width, z);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f(x*SmallMap, y, z);
    // 前面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y+Width, z-Height);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f(x*SmallMap, y+Width, z);
    // 后面
    glTexCoord2f(0.0f, 0.0f);  glVertex3f((x+Long)*SmallMap, y, z);
    glTexCoord2f(0.0f, Multiple*1.0f);  glVertex3f((x+Long)*SmallMap, y, z-Height);
    glTexCoord2f(Multiple*1.0f, Multiple*1.0f);  glVertex3f(x*SmallMap, y, z-Height);
    glTexCoord2f(Multiple*1.0f, 0.0f);  glVertex3f(x*SmallMap, y, z);
    glEnd();
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 

}
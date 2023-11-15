#include "world.h"

void World::DrawCoordinate(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    for(int i=0; i<3; ++i) {
        if(i == 1)
            glColor3f(0.0f,1.0f,0.0f);
        if(i == 2)
            glColor3f(0.0f,0.0f,1.0f);
        for(int j=0; j<2; ++j) {// 每条线段 2个顶点
            GLfloat x = CoordinatePoint[coordinateList[i][j]].x;
            GLfloat y = CoordinatePoint[coordinateList[i][j]].y;
            GLfloat z = CoordinatePoint[coordinateList[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

void World::DrawTestMaze(int SmallMap){
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    //画地板
    glBindTexture(GL_TEXTURE_2D, classflood);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(10.0f*SmallMap, 10.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(10.0f*SmallMap, 0.0f, 0.0f);
	glEnd();
    //画墙板
    glBindTexture(GL_TEXTURE_2D, classwall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f*SmallMap, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f*SmallMap, 0.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, classwall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(0.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, classwall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f*SmallMap, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f*SmallMap, 10.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, classwall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f*SmallMap, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f*SmallMap, 10.0f, 0.0f);
	glEnd();
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}
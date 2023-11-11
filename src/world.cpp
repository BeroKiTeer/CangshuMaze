#include "world.h"

World::World()
{
    for(int i = 0; i < 4; i++){
        CoordinatePoint.push_back(Point(
            coordinate[i][0],coordinate[i][1],coordinate[i][2]
        ));
    }
    flood = 0; wall = 0;
}

void World::DrawCoordinate()
{
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

void World::DrawTestMaze()
{
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    if(flood == 0){
        flood = loadTexture("texture/floor.bmp");
        if(flood == 0){
            std::cout << "图片加载失败" << std::endl;
            exit(0);
        }
    }
    if(wall == 0){
        wall = loadTexture("texture/wall.bmp");
        if(wall == 0){
            std::cout << "图片加载失败" << std::endl;
            exit(0);
        }
    }
    //画地板
    glBindTexture(GL_TEXTURE_2D, flood);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 80.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glTexCoord2f(80.0f, 80.0f); glVertex3f(10.0f, 10.0f, 0.0f);
	glTexCoord2f(80.0f, 0.0f); glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();
    //画墙板
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f, 0.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(0.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 10.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f, 10.0f, 0.0f);
	glEnd();
    glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 0.0f, -0.5f);
	glTexCoord2f(15.0f, 1.0f); glVertex3f(10.0f, 10.0f, -0.5f);
	glTexCoord2f(15.0f, 0.0f); glVertex3f(10.0f, 10.0f, 0.0f);
	glEnd();
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}
#include "smallmap.h"

void SmallMap::DrawMap(const RandomWallXOY& wall,const Point2d& pos, double Long){
    //画边界
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(-SmallMapSizeDouble, 0, 0, SmallMapSizeDouble);
    
    //边界
    glColor3f((float)(47/255.0), (float)(79/255.0), (float)(79/255.0));
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2d(0.0, 0.0);
        glVertex2d(-SmallMapSizeDouble, 0.0);

        glVertex2d(-SmallMapSizeDouble, 0.0);
        glVertex2d(-SmallMapSizeDouble, SmallMapSizeDouble);

        glVertex2d(-SmallMapSizeDouble, SmallMapSizeDouble);
        glVertex2d(0.0, SmallMapSizeDouble);

        glVertex2d(0.0, SmallMapSizeDouble);
        glVertex2d(0.0, 0.0);
    glEnd();

    //迷宫
    glLineWidth(1);
    glBegin(GL_LINES);
        for(auto i : wall.VWall){
            glVertex2d(-i.DrawX, i.DrawY);
            glVertex2d(-i.DrawX - i.LongX, i.DrawY);

            glVertex2d(-i.DrawX - i.LongX, i.DrawY);
            glVertex2d(-i.DrawX - i.LongX, i.DrawY + i.LongY);

            glVertex2d(-i.DrawX - i.LongX, i.DrawY + i.LongY);
            glVertex2d(-i.DrawX, i.DrawY + i.LongY);

            glVertex2d(-i.DrawX, i.DrawY + i.LongY);
            glVertex2d(-i.DrawX, i.DrawY);
        }
    glEnd();

    //人
    glLineWidth(1);
    glColor3f((float)(0/255.0), (float)(191/255.0), (float)(255/255.0));
    glBegin(GL_POLYGON);
        glVertex2d(-pos.x, pos.y);
        glVertex2d(-pos.x - Long, pos.y);
        glVertex2d(-pos.x - Long, pos.y + Long);
        glVertex2d(-pos.x, pos.y + Long);
    glEnd();
    glPopMatrix();
}
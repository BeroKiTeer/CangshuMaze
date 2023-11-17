#include "ball.h"
#include "config.h"
#include <vector>
Ball::Ball(Point P, GLfloat radius, GLint slices,GLint stacks):
    P(P),radius(radius),slices(slices),stacks(stacks){}

void Ball::render() 
{
	glEnable(GL_DEPTH_TEST);
	// 绘制球体 	
	glPushMatrix();
	glTranslatef(this->P.x,this->P.y,this->P.z);
	glColor3f(0.0, 0.0, 0.0);  // 设置颜色
	glutSolidSphere(radius, slices, stacks);  // 半径为1.0的球体，细分50x50
	glPopMatrix();
}

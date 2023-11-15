#include "ball.h"
#include "config.h"
#include <vector>
Ball::Ball(Point P, GLfloat radius, GLint slices,GLint stacks):
    P(P),radius(radius),slices(slices),stacks(stacks){}

void Ball::render() 
{
	// 绘制球体
	glColor3f(1.0, 1.0, 0.0);  // 设置颜色
	glutSolidSphere(radius, 50, 50);  // 半径为1.0的球体，细分50x50
}
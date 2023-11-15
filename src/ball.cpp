#include "ball.h"
#include "config.h"
#include <vector>
Ball::Ball(Point P, GLfloat radius, GLint slices,GLint stacks):
    P(P),radius(radius),slices(slices),stacks(stacks){}

<<<<<<< HEAD
// void Ball::generateVertices()
// {
//     for (int i = 0; i <= slices; ++i) {
//         for (int j = 0; j <= stacks; ++j) {
//             double phi = 2 * PI * i / slices;
//             double theta = PI * j / stacks;

//             double x = radius * sin(theta) * cos(phi);
//             double y = radius * cos(theta);
//             double z = radius * sin(theta) * sin(phi);

//             vertices.push_back({x, y, z});
//         }
//     }
// }

// void Ball::render()
// {
    
// }
=======
void Ball::render() 
{
	// 绘制球体
	glColor3f(1.0, 1.0, 0.0);  // 设置颜色
	glutSolidSphere(radius, 50, 50);  // 半径为1.0的球体，细分50x50
}
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8

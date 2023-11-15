#include "cylinder.h"

inline std::vector<Point> Cylinder::get_topCircle() const 
{ 
    return topCircle; 
}
inline std::vector<Point> Cylinder::get_bottomCircle() const 
{ 
    return bottomCircle; 
}
void Cylinder::set_topCircle(const std::vector<Point> &topCircle) 
{
    this->topCircle = topCircle; 
}
void Cylinder::set_bottomCircle(const std::vector<Point> &bottomCircle) 
{
    this->bottomCircle = bottomCircle; 
}

Cylinder::Cylinder(GLfloat radius, GLfloat height, GLint segments)
:radius(radius),height(height),segments(segments)
{
    diameter = 2*radius;
    getCircle(x, y, radius, z, bottomCircle);
    getCircle(x, y, radius, z + height, topCircle);
}

Cylinder::Cylinder(Point p, GLfloat radius, GLfloat height, GLint segments)
:p(p),radius(radius),height(height),segments(segments)
{
    diameter = 2*radius;
    getCircle(p.x, p.y, radius, p.z, bottomCircle);
    getCircle(p.x, p.y, radius, p.z + height, topCircle);
}

Cylinder::Cylinder(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLfloat height, GLint segments)
:x(x),y(y),z(z),radius(radius),height(height),segments(segments)
{
    diameter = 2*radius;
    getCircle(x, y, radius, z, bottomCircle);
    getCircle(x, y, radius, z + height, topCircle);
}

void Cylinder::render()
{
    glEnable(GL_DEPTH_TEST);
    // glBegin(GL_LINE_LOOP);
    // glColor3f(0.0, 0.0, 1.0);  // 设置颜色
    // for (const auto& point : bottomCircle) {
    //     glVertex3d(point.x, point.y, point.z);
    // }
    // glEnd();

    // // 渲染顶部圆形
    // glBegin(GL_LINE_LOOP);
    // glColor3f(0.0, 0.0, 1.0);  // 设置颜色
    // for (const auto& point : topCircle) {
    //     glVertex3d(point.x, point.y, point.z);
    // }
    // glEnd();
    glTranslatef(this->p.x,this->p.y,this->p.z);
    
	// 绘制圆柱侧面
	glColor3f(1.0, 1.0, 0.0);  // 设置颜色
	
	// 使用gluCylinder绘制圆柱
	GLUquadric* quadric = gluNewQuadric();
	gluCylinder(quadric, radius, radius, height, 50, 50);  // 底面和顶面半径均为1.0，高度为2.0，细分50x50
	gluDeleteQuadric(quadric);
	
}
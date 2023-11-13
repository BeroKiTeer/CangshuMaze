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
    glBegin(GL_TRIANGLE_FAN);
    for (const auto& point : bottomCircle) {
        glVertex3d(point.x, point.y, point.z);
    }
    glEnd();

    // 渲染顶部圆形
    glBegin(GL_TRIANGLE_FAN);
    for (const auto& point : topCircle) {
        glVertex3d(point.x, point.y, point.z);
    }
    glEnd();

    // 渲染侧面
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        double theta = 2.0 * PI * i / segments;
        double dx = radius * cos(theta);
        double dy = radius * sin(theta);

        // 底部点
        glVertex3d(x + dx, y + dy, z);

        // 顶部点
        glVertex3d(x + dx, y + dy, z + height);
    }
    glEnd();
}
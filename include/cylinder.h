#include <vector>
#include <cmath>
#include <algorithm>
#include <GL/gl.h>
#include "config.h"

class Cylinder {
public:
    Cylinder(GLfloat radius,GLfloat height, GLint segments);
    Cylinder(Point p,GLfloat radius,GLfloat height, GLint segments);
    Cylinder(GLfloat x, GLfloat y, GLfloat z,GLfloat radius,GLfloat height, GLint segments);

    void render();
private:
    GLfloat radius;
    GLfloat height;
    GLfloat diameter;
    GLint segments = 30;
    Point p;        //圆柱中心点
    GLfloat x,y,z;  //圆柱中心点

    std::vector<Point> topCircle; // 顶部圆形的顶点
    std::vector<Point> bottomCircle;  // 底部圆形的顶点
};
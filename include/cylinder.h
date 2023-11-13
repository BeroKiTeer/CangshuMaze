#include <vector>
#include <cmath>
#include <algorithm>
#include <GL/gl.h>
#include "config.h"

class Cylinder {
public:
    Cylinder(GLfloat radius,GLfloat height, GLint segments);
    Cylinder(Point p, GLfloat radius, GLfloat height, GLint segments);
    Cylinder(GLfloat x, GLfloat y, GLfloat z,GLfloat radius,GLfloat height, GLint segments);
    inline std::vector<Point> get_topCircle() const;
    inline std::vector<Point> get_bottomCircle() const;
    void set_topCircle(const std::vector<Point> &topCircle);
    void set_bottomCircle(const std::vector<Point> &bottomCircle);

    void render();
    
    std::vector<Point> topCircle; // 顶部圆形的顶点
    std::vector<Point> bottomCircle;  // 底部圆形的顶点
private:
    GLfloat radius;
    GLfloat height;
    GLfloat diameter;
    GLint segments;
    Point top,bottom;        //圆柱顶点，圆柱底部
    GLfloat x,y,z;  //圆柱中心点

    Point p;
};
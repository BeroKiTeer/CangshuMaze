#include <vector>
#include <cmath>
#include <algorithm>
#include <GL/gl.h>
#include "config.h"

class Cylinder {
public:
    Cylinder(GLfloat radius,GLfloat height, GLint segments);

    void GenerateCylinderVertices();

    void render();
private:
    GLfloat radius;
    GLfloat height;
    GLint segments;

    std::vector<GLfloat> vertices; // 顶点坐标
    std::vector<GLfloat> normals;  // 法线
};
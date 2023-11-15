#pragma once
#include <gl/freeglut.h>
#include "transform.h"
#include "config.h"
#include "shader.h"
class SkyBox {
public:
    SkyBox();
    void ShowSky();
private:
    VP SkyBoxPoint;
    //Top,down,front,left,right,back;
    GLuint Surface[6];
    double Distance;
};
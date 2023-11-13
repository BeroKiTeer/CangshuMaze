#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <gl/gl.h>
#include <string>
#include <gl/gl.h>
#include "config.h"
#include "shader.h"

class SkyBox {
public:
    SkyBox();
    ~SkyBox() = default;

    void ShowSky();
    
private:
    std::vector<Point> SkyBoxPoint;
    //Top,down,front,left,right,back;
    GLuint Surface[6];
    double Distance;
};
#pragma once
<<<<<<< HEAD
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
=======
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
>>>>>>> e6b1af9fa60f40ba4647fda3ef89bcaab7e89af8
    //Top,down,front,left,right,back;
    GLuint Surface[6];
    double Distance;
};
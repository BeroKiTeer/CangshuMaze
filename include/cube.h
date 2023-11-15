#pragma once
#include <GL/gl.h>
#include "sharedData.h"
#include "transform.h"

extern GLuint TextureWallID;
extern GLuint TextureFloorID;
extern GLuint TextureTextcurbID;

class Cube {
public:
    Cube(
        double x, double y, double z, 
        double Long, double Width, double Height
    ):x(x),y(y),z(z),Long(Long),Width(Width),Height(Height){
    }
    
    Cube():x(0),y(0),z(0),Long(1.0),Width(1.0),Height(1.0){
    }

    void render_wall(int SmallMap){
        this->SmallMap = SmallMap;
        render(TextureWallID);
    }
    void render_floor(int SmallMap){ 
        this->SmallMap = SmallMap;
        render(TextureFloorID);
    }
private:
    void render(GLuint id);
private:
    double Long;
    double Width;
    double Height;
    double x,y,z;
    double Multiple = 3;
    int SmallMap;
};
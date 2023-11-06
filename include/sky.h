#pragma once
#include <vector>
#include <string>
#include <gl/gl.h>
#include "config.h"

class SkyBox {
    SkyBox() = default;
    SkyBox(GLuint skyboxTexture);
    ~SkyBox() = default;

    void init(const std::vector<std::string>& texturePaths);
    void render();
    void Cleanup();

    inline GLuint get_skyboxTexture();
    void set_skyboxTexture(const GLuint &skyboxTexture);

    
private:
    std::vector<Point>sky;
    GLuint skyboxTexture;
};
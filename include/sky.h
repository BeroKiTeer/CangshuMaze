#pragma once
#include <vector>
#include "config.h"

class Sky {
    void addSky();
    //
    void makeSky();
    //定义天空盒顶点
private:
    std::vector<Point>sky;
};
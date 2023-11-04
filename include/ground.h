#pragma once
#include <vector>
#include "config.h"
class Ground{
public:
    Ground() = default;
    ~Ground() = default;
    void getGround();
    void addGround();
private:
    std::vector<Point>ground;
};
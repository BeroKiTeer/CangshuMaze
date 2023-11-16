#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "config.h"

using namespace std;
struct Line{
    Point2d p1;
    Point2d p2;
    Line(Point2d p1, Point2d p2):p1(p1),p2(p2){}
};

struct chunk { 
    int v1, v2, Rval;
    bool operator<(const chunk& a){
        return this->Rval < a.Rval;
    }

    bool operator>(const chunk& a){
        return this->Rval > a.Rval;
    }
};

class RandomWallXOY{
public:
    vector<WallXOY> VWall;
    RandomWallXOY(){}
    void showWall(){
        for(auto i : VWall){
            std::cout << i.DrawX << " " << i.DrawY << std::endl;
        }
    }
    void RandomWall(){
        genWall();
        adjectWallPos();
    }
private:
    int  bczfind(int x);
    bool bczmerge(int x, int y);
    void genWall();
    void adjectWallPos();
private:
    vector<chunk> VChunk, DrawChunk;
    vector<Line> VLine;
private:
    const double WorldMapSize = 10.0f;
    const double SaveEdge = 0.25f;
    const double length = WorldMapSize - SaveEdge*2;
    const int MAPSIZE =  18;
    const int RAMDOMNESS = 65535;
    const double PointCenterDistance = (length/MAPSIZE) / 2;
    const double P2PDistance = length/MAPSIZE;
    int arr[100010];
};
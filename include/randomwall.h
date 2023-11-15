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

struct WallXOZ{
    double DrawX, DrawY; //画点位置
    double LongX;    //x轴长度
    double LongY;   //y轴长度
    //p2永远是靠近原点的
    Point2d p1;
    Point2d p2;
    double Width;
    WallXOZ(Point2d p1, Point2d p2):p1(p1),p2(p2),Width(0.075){
        CalcDraw();
    }
    WallXOZ(Point2d p1, Point2d p2, double Width):p1(p1),p2(p2),Width(Width){
        CalcDraw();
    }
    WallXOZ(){}
private:
    void CalcDraw(){
        if(p1.x != p2.x){
            LongX = p1.x - p2.x + Width*2;
            LongY = Width*2;
            DrawX = p2.x - Width;
            DrawY = p2.y - Width;
        }
        else{
            LongY = p1.y - p2.y + Width*2;
            LongX = Width*2;
            DrawX = p2.x - Width;
            DrawY = p2.y - Width;
        }
    }
};

class RandomWallXOY{
public:
    vector<WallXOZ> VWall;
    RandomWallXOY(){
        genWall();
        adjectWallPos();
    }
    void showWall(){
        for(auto i : VWall){
            std::cout << i.DrawX << " " << i.DrawY << std::endl;
        }
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
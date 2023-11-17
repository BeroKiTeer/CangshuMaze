#pragma once
#include <cmath>
#include <iostream>
#include "line.h"
#include "circle.h"
#define GLUT_WHEEL_UP 3
#define GLUT_WHEEL_DOWN 4
typedef unsigned int UINT;
const double WHITE[3] = {1, 1, 1};
const double RED[3] = {1, 0, 0};
const double YELLOW[3] = {1, 1, 0};
const double GREEN[3] = {0, 1, 0};
const double BLACK[3] = {-1, -1, -1};
const double DARKBLUE[3] = {0.2, 0.2, 0.6};
const double DARKRED[3] = {0.6, 0.2, 0.2};
const double DARKGREEN[3] = {0.2, 0.6, 0.2};
const double PI = 4*atan(1);
struct Point {
    double x,y,z;
    Point() = default;
    ~Point() = default;
    Point(double x, double y, double z):x(x),y(y),z(z){}
};

struct Point2d{
    double x, y;
    Point2d():x(0.0),y(0.0){};
    Point2d(double x, double y):x(x),y(y){};
};

struct WallXOY{
    double DrawX, DrawY; //画点位置
    double LongX;    //x轴长度
    double LongY;   //y轴长度
    //p2永远是靠近原点的
    Point2d p1;
    Point2d p2;
    double Width;
    WallXOY(Point2d p1, Point2d p2):p1(p1),p2(p2),Width(0.075){
        CalcDraw();
    }
    WallXOY(Point2d p1, Point2d p2, double Width):p1(p1),p2(p2),Width(Width){
        CalcDraw();
    }
    WallXOY():p1(Point2d(0.0, 0.0)),p2(Point2d(0.0,0.0)),Width(0.0){}

    bool operator==(const WallXOY& a){
        return (this->DrawX == a.DrawX && this->DrawY == a.DrawY &&
                this->LongX == a.LongX && this->LongY == a.LongY);
    }
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

// struct OrientWASD{
//     bool Up, Down, Left, Right;
//     WallXOY wall;

//     OrientWASD():Up(true),Down(true),Left(true),Right(true){}
//     OrientWASD(bool Up, bool Down, bool Left, bool Right,WallXOY wall):Up(Up),
//     Down(Down),Left(Left),Right(Right),wall(wall){}
//     OrientWASD(bool Up, bool Down, bool Left, bool Right):Up(Up),
//     Down(Down),Left(Left),Right(Right){}

//     OrientWASD operator|(const OrientWASD& a){
//         return OrientWASD(
//             this->Up || a.Up, this->Down || a.Down, 
//             this->Left || a.Left, this->Right || a.Right);
//     }
//     OrientWASD operator&(const OrientWASD& a){
//         return OrientWASD(
//             this->Up && a.Up, this->Down && a.Down, 
//             this->Left && a.Left, this->Right && a.Right);
//     }

//     bool operator==(const OrientWASD& a){
//         return (this->Up == a.Up && this->Down == a.Down &&
//                 this->Left == a.Left && this->Right == a.Right && this->wall == wall);
//     }

//     void GetInfo(){
//         if(!Left && !Up)
//             std::cout << "LeftUp" << std::endl;
//         if(!Left && !Down)
//             std::cout << "LeftDown" << std::endl;
//         if(!Right && !Up)
//             std::cout << "RightUp" << std::endl;
//         if(!Right && !Down)
//             std::cout << "RightDown"  << std::endl;
//     }
// };


//编译会出错，只能定义常量
//mingw-make clean之后看看结果
//先清理在编译
// int a;

const UINT WindowsWidth = 800;
const UINT WindowsHeight = 800;
const UINT SmallMapSizeINT = 400;
const double SmallMapSizeDouble = 10.0;
#define ACTCOLOR WHITE
#define GROUNDCOLOR RED
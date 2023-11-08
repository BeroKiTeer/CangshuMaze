#pragma once
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include "config.h"
#define PI 4*atan(1)

struct Matrix3D{
	double x,y,z,N;
	Matrix3D(double x, double y, double z, double N):x(x),y(y),z(z),N(N){};
};

struct Matrix2D{
	double x,y,N;
	Matrix2D(double x, double y, double N):x(x),y(y),N(N){};
};

typedef std::vector<Matrix3D> VMatrix3D;
typedef std::vector<Matrix2D> VMatrix2D;
typedef std::vector<Point> VP;
typedef std::vector<Point2d> VP2;
typedef unsigned int UINT;

//矩阵相乘,点矩阵转换,Debug信息调试 	√
void _MultipleMatriex3D(VMatrix3D& MatrixA_IN, VMatrix3D& MatrixB_IN);
void _MultipleMatriex2D(VMatrix2D& MatrixA_IN, VMatrix2D& MatrixB_IN);
void _Point3DToMatriex3D(VP& PointGroup, VMatrix3D& Matrix, bool PtoM);
void _Point2DToMatriex2D(VP2& PointGroup, VMatrix2D& Matrix, bool PtoM);
void PrintPoint(const VP& Point);
void PrintMatriex3D(const VMatrix3D& Matrix);

//平移变换	√
void _translate(VMatrix3D &In, double l, double m, double n);

void translateX(VP &v, double l);
void translateY(VP &v, double m);
void translateZ(VP &v, double n);
void translate(VP &v, double l, double m, double n);

// VP translateX(double l);
// VP translateY(double m);
// VP translateZ(double n);

//比例变换 	√
void _scaleXYZ(VMatrix3D &In, double a, double e, double i);

void scaleX(VP &v, double a);
void scaleY(VP &v, double e);
void scaleZ(VP &v, double i);
void scaleEntirety(VP &v, double s);
void scaleXYZ(VP &v, double a, double e, double i);

// std::vector <Point> scaleX(double a);
// std::vector <Point> scaleY(double e);
// std::vector <Point> scaleZ(double i);
// std::vector <Point> scale(double a, double e, double i);
// std::vector <Point>scale(double s);


//旋转操作 	√	前者是弧度，后者是角度
void _rotate(VMatrix3D &In, double dx, double dy, double dz);

// void rotateX(VP &v, double angle);
// void rotateY(VP &v, double angle);
// void rotateZ(VP &v, double angle);
// void rotateXYZ(VP &v, double angle1, double angle2, double angle3);
// std::vector <Point> rotateX(double angle);
// std::vector <Point> rotateY(double angle);
// std::vector <Point> rotateZ(double angle);


void rotateDX(VP &v, double angle);
void rotateDY(VP &v, double angle);
void rotateDZ(VP &v, double angle);
void rotateDXYZ(VP &v, double angle1, double angle2, double angle3);

// void _TTop(VMatrix3D &In);

VP2 TTop(const VP &v);

// std::vector<Point2> TFront(VP &v);
// std::vector<Point2> TSide(VP &v);

// std::vector <Point> rotateDX(double angle);
// std::vector <Point> rotateDY(double angle);
// std::vector <Point> rotateDZ(double angle);

// //关于坐标轴的对称变换
// void symX(std::vector <Point> &v);
// void symY(std::vector <Point> &v);
// void symZ(std::vector <Point> &v);
// std::vector <Point> symX();
// std::vector <Point> symY();
// std::vector <Point> symZ();
// //关于坐标平面的对称变换
// void symXOY(std::vector <Point> &v);
// void symYOZ(std::vector <Point> &v);
// void symZOX(std::vector <Point> &v);
// std::vector <Point> symXOY();
// std::vector <Point> symYOZ();
// std::vector <Point> symZOX();
// //关于原点的对称变换
// void symO(std::vector <Point> &v);
// std::vector <Point> symO();

// //错切变换
// void shearX(std::vector <Point> &v, double d, double g);
// void shearY(std::vector <Point> &v, double b, double h);
// void shearZ(std::vector <Point> &v, double c, double f);
// std::vector <Point> shearX(double d, double g);
// std::vector <Point> shearY(double b, double h);
// std::vector <Point> shearZ(double c, double f);
// void shear(std::vector <Point> &v, double d, double g, double b, double h, double c, double f);
// std::vector <Point> shear(double d, double g, double b, double h, double c, double f);


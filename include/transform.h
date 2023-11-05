#pragma once
/*
变换矩阵
*/
#include <algorithm>
#include <vector>

struct Point;

//二维齐次坐标变换矩阵
void transform(std::vector<Point>&v,
	double a,double b,double p,
	double c,double d,double q,
	double l,double m,double s);
std::vector<Point> transform(
	double a,double b,double p,
	double c,double d,double q,
	double l,double m,double s);

//三维齐次坐标变换矩阵
void transform(std::vector<Point>&v,
	double a,double b,double c,double p,
	double d,double e,double f,double q,
	double g,double h,double i,double r,
	double l,double m,double n,double s);
std::vector<Point> transform(
	double a,double b,double c,double p,
	double d,double e,double f,double q,
	double g,double h,double i,double r,
	double l,double m,double n,double s);

//平移变换	
void translateX(std::vector <Point> &v, double l);
void translateY(std::vector <Point> &v, double m);
void translateZ(std::vector <Point> &v, double n);
std::vector <Point> translateX(double l);
std::vector <Point> translateY(double m);
std::vector <Point> translateZ(double n);
//整体平移变换
void translate(std::vector <Point> &v, double l, double m, double n);
std::vector <Point> translate(double l, double m, double n);

//整体比例变换
void scale(std::vector <Point> &v, double s);
std::vector <Point>scale(double s);
//沿轴缩放
void scaleX(std::vector <Point> &v, double a);
void scaleY(std::vector <Point> &v, double e);
void scaleZ(std::vector <Point> &v, double i);
std::vector <Point> scaleX(double a);
std::vector <Point> scaleY(double e);
std::vector <Point> scaleZ(double i);
//自定义缩放
void scale(std::vector <Point> &v, double a, double e, double i);
std::vector <Point> scale(double a, double e, double i);

//旋转操作（单位是弧度）
void rotateX(std::vector <Point> &v, double angle);
void rotateY(std::vector <Point> &v, double angle);
void rotateZ(std::vector <Point> &v, double angle);
std::vector <Point> rotateX(double angle);
std::vector <Point> rotateY(double angle);
std::vector <Point> rotateZ(double angle);
//旋转操作（单位是角度）
void rotateDX(std::vector <Point> &v, double angle);
void rotateDY(std::vector <Point> &v, double angle);
void rotateDZ(std::vector <Point> &v, double angle);
std::vector <Point> rotateDX(double angle);
std::vector <Point> rotateDY(double angle);
std::vector <Point> rotateDZ(double angle);

//关于坐标轴的对称变换
void symX(std::vector <Point> &v);
void symY(std::vector <Point> &v);
void symZ(std::vector <Point> &v);
std::vector <Point> symX();
std::vector <Point> symY();
std::vector <Point> symZ();
//关于坐标平面的对称变换
void symXOY(std::vector <Point> &v);
void symYOZ(std::vector <Point> &v);
void symZOX(std::vector <Point> &v);
std::vector <Point> symXOY();
std::vector <Point> symYOZ();
std::vector <Point> symZOX();
//关于原点的对称变换
void symO(std::vector <Point> &v);
std::vector <Point> symO();

//错切变换
void shearX(std::vector <Point> &v, double d, double g);
void shearY(std::vector <Point> &v, double b, double h);
void shearZ(std::vector <Point> &v, double c, double f);
std::vector <Point> shearX(double d, double g);
std::vector <Point> shearY(double b, double h);
std::vector <Point> shearZ(double c, double f);
void shear(std::vector <Point> &v, double d, double g, double b, double h, double c, double f);
std::vector <Point> shear(double d, double g, double b, double h, double c, double f);

//三视图
std::vector<Point> TFront();
std::vector<Point> TTop();
std::vector<Point> TSide();
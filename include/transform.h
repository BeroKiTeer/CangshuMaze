#pragma once
/*
变换矩阵
*/
#include <vector>

struct Point;

void translateX(std::vector <Point> &v, double l);
void translateY(std::vector <Point> &v, double m);
void translateZ(std::vector <Point> &v, double n);
void translate(std::vector <Point> &v, double l, double m, double n);

void scale(std::vector <Point> &v, double s);
void scaleX(std::vector <Point> &v, double a);
void scaleY(std::vector <Point> &v, double e);
void scaleZ(std::vector <Point> &v, double i);
void scale(std::vector <Point> &v, double a, double e, double i);

void rotateRX(std::vector <Point> &v, double angle);
void rotateX(std::vector <Point> &v, double angle);
void rotateRY(std::vector <Point> &v, double angle);
void rotateY(std::vector <Point> &v, double angle);
void rotateRZ(std::vector <Point> &v, double angle);
void rotateZ(std::vector <Point> &v, double angle);
void rotateDX(std::vector <Point> &v, double angle);
void rotateDY(std::vector <Point> &v, double angle);

void initInd(const std::vector <Point> &leftLeg, const std::vector <Point> &rightLeg,
	const std::vector <Point> &leftArm, const std::vector <Point> &rightArm);
void rotateIndLeftLeg(std::vector <Point> &v, double angle);
void rotateIndRightLeg(std::vector <Point> &v, double angle);
void rotateIndLeftArm(std::vector <Point> &v, double angle);
void rotateIndRightArm(std::vector <Point> &v, double angle);
void swingIndArm(double angle, double depth);
void swingIndLeg(double angle, double depth);
void bodyTranslateY(double delta);

void rotateDZ(std::vector <Point> &v, double angle);
void symX(std::vector <Point> &v);
void symY(std::vector <Point> &v);
void symZ(std::vector <Point> &v);
void symXOY(std::vector <Point> &v);
void symYOZ(std::vector <Point> &v);
void symZOX(std::vector <Point> &v);
void symO(std::vector <Point> &v);

void shearX(std::vector <Point> &v, double d, double g);
void shearY(std::vector <Point> &v, double b, double h);
void shearZ(std::vector <Point> &v, double c, double f);
void shear(std::vector <Point> &v, double d, double g, double b, double h, double c, double f);

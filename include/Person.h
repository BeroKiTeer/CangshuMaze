#pragma once
#include <iostream>
#include <vector>
#include "config.h"
#include"cylinder.h"
#include"transform.h"
#include"ball.h"
#include"camera.h"
class Person:public Cylinder 
{
public:    
    Person() = default;
    ~Person() = default;

    void draw();
    void move(double delx,double dely);//移动
    void makeMatch(double topx, double topy, double bottomx, double bottomy,
    double matchWidth, double topd, double bottomd, std::vector <Point> &res);
    //其实就是画圆柱，用于创建一个特定部分（比如腿、手臂等）的3D模型
    /*
            输入参数：
            topx, topy：顶部圆柱体的中心坐标。
            bottomx, bottomy：底部圆柱体的中心坐标。
            matchWidth：圆柱体的直径（宽度）。
            topd：顶部圆柱体的高度。
            bottomd：底部圆柱体的高度。
            getCircle 函数被调用两次来获取顶部和底部圆柱体的顶点信息，这些信息存储在 top 和 bottom 向量中。
     * 
     */
    //：一个顶部圆柱体和一个底部圆柱体。
    
    void makeBody();//创建角色身体
    // void initInd(const std::vector <Point> &leftLeg, const std::vector <Point> &rightLeg,
	// const std::vector <Point> &leftArm, const std::vector <Point> &rightArm);

    //移动时的动作
    void rotateIndLeftLeg(double angle);
    void rotateIndRightLeg(double angle);
    void rotateIndLeftArm(double angle);
    void rotateIndRightArm(double angle);
    void swingIndArm(double angle, double depth);
    void swingIndLeg(double angle, double depth);
    void bodyTranslateY(double delta);
    void bodyTranslateX(double delta);
    
    Cylinder *leftLeg, *rightLeg, *leftArm, *rightArm,*Body;
    Ball* head;


protected:
    bool visable = true;
    bool firstPerson;

    bool moveLeft = false, moveRight = false, moveForward = false, moveBack = false;//人物移动
    bool jump = false,turnLeft = false,turnRight = false;

private:
    //人物属性
    double bodyWidth = 3, bodyHeight = 100, armStepWidth = 20,
    legStepWidth = 15, armLongerThanLeg = 10;

};
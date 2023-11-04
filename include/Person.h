#pragma once
#include <iostream>
#include <vector>
#include "config.h"
class Person {
public:    
    Person() = default;
    ~Person() = default;

    void draw();
    void move(double delx,double delz);//移动
    void makeMatch(double topx, double topy, double bottomx, double bottomy,
    double matchWidth, double topd, double bottomd, std::vector <Point> &res);
    //用于创建一个特定部分（比如腿、手臂等）的3D模型，该部分由两个圆柱体组成
    //：一个顶部圆柱体和一个底部圆柱体。
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
    void makeBody();//创建角色身体
    void initInd(const std::vector <Point> &leftLeg, const std::vector <Point> &rightLeg,
	const std::vector <Point> &leftArm, const std::vector <Point> &rightArm);
    void rotateIndLeftLeg(std::vector <Point> &v, double angle);
    void rotateIndRightLeg(std::vector <Point> &v, double angle);
    void rotateIndLeftArm(std::vector <Point> &v, double angle);
    void rotateIndRightArm(std::vector <Point> &v, double angle);
    void swingIndArm(double angle, double depth);
    void swingIndLeg(double angle, double depth);
    void bodyTranslateY(double delta);

private:
    double bodyWidth = 3, bodyHeight = 100, armStepWidth = 20,
    legStepWidth = 15, armLongerThanLeg = 10;
    bool visable = true;
};
#include"Person.h"

void Person::makeBody()
{
    this->Body=new Cylinder(Point(50,50,80),Point(50,50,55),10.0f,30);
    this->leftArm=new Cylinder(Point(40,50,80),Point(40,50,45),10.0f,30);
    this->rightArm=new Cylinder(Point(60,50,80),Point(60,50,45),10.0f,30);
    this->leftleg=new Cylinder(Point(45,50,35),Point(45,50,0),5.0f,30);
    this->rightleg=new Cylinder(Point(55,50,35),Point(55,50,0),5.0f,30);
}


void Person::rotateIndLeftLeg(double angle)
{
    Cylinder res=leftArm;

    double EachStepAngle=angle*atan(1)/45;
    double c=cos(angle),s=sin(angle);
    double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    leftArm=res;   

}

void Person::rotateIndLeftLeg(double angle)
{
    Cylinder res=leftLeg;

    double EachStepAngle=angle*atan(1)/45;
    double c=cos(angle),s=sin(angle);
    double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    leftLeg=res;   

}

void Person::rotateIndRightArm(double angle)
{
    Cylinder res=rightArm;

    double EachStepAngle=angle*atan(1)/45;
    double c=cos(angle),s=sin(angle);
    double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    rightArm=res;   

}

void Person::rotateIndRightLeg(double angle)
{
    Cylinder res=rightLeg;

    double EachStepAngle=angle*atan(1)/45;
    double c=cos(angle),s=sin(angle);
    double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    rightLeg=res;   

}

void Person::swingIndArm(double angle,double depth)
{
    Cylinder resLeft=leftArm,resRight=rightArm;
    rotateDX(resLeft.topCircle,angle*atan(1)/45);
    rotateDX(resLeft.bottomCircle,angle*atan(1)/45);
    rotateDX(resRight.topCircle,-angle*atan(1)/45);
    rotateDX(resRight.bottomCircle,-angle*atan(1)/45);
    leftArm=resLeft,rightArm=resRight;

}

void Person::swingIndLeg(double angle,double depth)
{
    Cylinder resLeft=leftLeg,resRight=rightLeg;
    rotateDX(resLeft.topCircle,angle*atan(1)/45);
    rotateDX(resLeft.bottomCircle,angle*atan(1)/45);
    rotateDX(resRight.topCircle,-angle*atan(1)/45);
    rotateDX(resRight.bottomCircle,-angle*atan(1)/45);
    leftLeg=resLeft,rightLeg=resRight;
}

void Person::bodyTranslateY(double delta)
{
    Cylinder resLeftArm=leftArm,resRightArm=rightArm,resLeftLeg=leftLeg,resRightLeg=rightLeg;
    translateY(resLeftArm.topCircle,delta);
    translateY(resLeftArm.bottomCircle,delta);
    translateY(resRightArm.topCircle,delta);
    translateY(resRightArm.bottomCircle,delta);
    translateY(resLeftLeg.topCircle,delta);
    translateY(resLeftLeg.bottomCircle,delta);
    translateY(resRightLeg.topCircle,delta);
    translateY(resRightLeg.bottomCircle,delta);
    leftArm=resLeftArm,leftLeg=resLeftLeg,rightArm=resRightArm,rightLeg=resRightLeg;
}

void Person::move(double delx,double dely)
{

}

void Person::draw()
{
    
}
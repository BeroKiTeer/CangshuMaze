#include"Person.h"

Point Person::pos = {0,0,0};

Person::Person():Listener()
{
    this->head=new Ball(Point(0.5+pos.x,0.5+pos.y,-0.425+pos.z),0.05f,30,30);
    this->Body=new Cylinder(Point(0.5+pos.x,0.5+pos.y,-0.375+pos.z),0.05f,0.25,30);
    this->leftArm=new Cylinder(Point(0.425+pos.x,0.5+pos.y,-0.375+pos.z),0.025f,0.25,30);
    this->rightArm=new Cylinder(Point(0.575+pos.x,0.5+pos.y,-0.375+pos.z),0.025f,0.25,30);
    this->leftLeg=new Cylinder(Point(0.475+pos.x,0.5+pos.y,-0.25+pos.z),0.025f,0.25,30);
    this->rightLeg=new Cylinder(Point(0.525+pos.x,0.5+pos.y,-0.25+pos.z),0.025f,0.25,30);
    head->render();
    Body->render();
    leftArm->render();
    rightArm->render();
    leftLeg->render();
    rightLeg->render();
}

Person::~Person()
{
    delete this->head;
    delete this->Body;
    delete this->leftArm;
    delete this->rightArm;
    delete this->leftLeg;
    delete this->rightLeg;
}

void Person::rotateIndLeftArm(double angle)
{
    Cylinder res=*leftArm;

    double EachStepAngle=angle*atan(1)/45;

    rotateDZ(res.topCircle,EachStepAngle);
    rotateDZ(res.bottomCircle,EachStepAngle);

    // double c=cos(angle),s=sin(angle);
    // double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    // res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    // res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    // res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    // res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    // res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    // res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    *leftArm=res;   

}

void Person::rotateIndLeftLeg(double angle)
{
    Cylinder res=*leftLeg;

    double EachStepAngle=angle*atan(1)/45;
    
    rotateDZ(res.topCircle,EachStepAngle);
    rotateDZ(res.bottomCircle,EachStepAngle);

    // double c=cos(angle),s=sin(angle);
    // double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    // res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    // res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    // res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    // res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    // res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    // res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    *leftLeg=res;   

}

void Person::rotateIndRightArm(double angle)
{
    Cylinder res=*rightArm;

    double EachStepAngle=angle*atan(1)/45;

    
    rotateDZ(res.topCircle,EachStepAngle);
    rotateDZ(res.bottomCircle,EachStepAngle);

    // double c=cos(angle),s=sin(angle);
    // double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    // res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    // res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    // res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    // res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    // res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    // res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    *rightArm=res;   

}

void Person::rotateIndRightLeg(double angle)
{
    Cylinder res=*rightLeg;

    double EachStepAngle=angle*atan(1)/45;


    rotateDZ(res.topCircle,EachStepAngle);
    rotateDZ(res.bottomCircle,EachStepAngle);
    std::cout<<"角度："<<res.topCircle[0].x<<' '<<res.topCircle[0].y<<' '<<res.topCircle[0].z<<endl;
    // double c=cos(angle),s=sin(angle);
    // double transMartix[4][4]={{c,0,s,0},{0,1,0,0},{-s,0,c,0},{0,0,0,1}};

    // res.topCircle.x=transMartix[0][0]*res.topCircle.x+transMartix[0][1]*res.topCircle.y+transMartix[0][2]*res.topCircle.z+transMartix[0][3];
    // res.topCircle.y=transMartix[1][0]*res.topCircle.x+transMartix[1][1]*res.topCircle.y+transMartix[1][2]*res.topCircle.z+transMartix[1][3];
    // res.topCircle.z=transMartix[2][0]*res.topCircle.x+transMartix[2][1]*res.topCircle.y+transMartix[2][2]*res.topCircle.z+transMartix[2][3];

    // res.bottomCircle.x=transMartix[0][0]*res.bottomCircle.x+transMartix[0][1]*res.bottomCircle.y+transMartix[0][2]*res.bottomCircle.z+transMartix[0][3];
    // res.bottomCircle.y=transMartix[1][0]*res.bottomCircle.x+transMartix[1][1]*res.bottomCircle.y+transMartix[1][2]*res.bottomCircle.z+transMartix[1][3];
    // res.bottomCircle.z=transMartix[2][0]*res.bottomCircle.x+transMartix[2][1]*res.bottomCircle.y+transMartix[2][2]*res.bottomCircle.z+transMartix[2][3];

    *rightLeg=res;   

}

void Person::swingIndArm(double angle,double depth)
{
    Cylinder resLeft=*leftArm,resRight=*rightArm;
    rotateDX(resLeft.topCircle,angle*atan(1)/45);
    rotateDX(resLeft.bottomCircle,angle*atan(1)/45);
    rotateDX(resRight.topCircle,-angle*atan(1)/45);
    rotateDX(resRight.bottomCircle,-angle*atan(1)/45);
    *leftArm=resLeft,*rightArm=resRight;

}

void Person::swingIndLeg(double angle,double depth)
{
    Cylinder resLeft=*leftLeg,resRight=*rightLeg;
    rotateDX(resLeft.topCircle,angle*atan(1)/45);
    std::cout<<resLeft.topCircle[0].x<<' '<<resLeft.topCircle[0].y<<' '<<resLeft.topCircle[0].z<<endl;
    rotateDX(resLeft.bottomCircle,angle*atan(1)/45);
    rotateDX(resRight.topCircle,-angle*atan(1)/45);
    rotateDX(resRight.bottomCircle,-angle*atan(1)/45);
    *leftLeg=resLeft,*rightLeg=resRight;
}

void Person::bodyTranslateY(double delta)
{
    Cylinder resBody=*Body,resLeftArm=*leftArm,resRightArm=*rightArm,resLeftLeg=*leftLeg,resRightLeg=*rightLeg;
    translateY(resBody.topCircle,delta);
    translateY(resBody.bottomCircle,delta);

    translateY(resLeftArm.topCircle,delta);
    translateY(resLeftArm.bottomCircle,delta);

    translateY(resRightArm.topCircle,delta);
    translateY(resRightArm.bottomCircle,delta);
    
    translateY(resLeftLeg.topCircle,delta);
    translateY(resLeftLeg.bottomCircle,delta);
    
    translateY(resRightLeg.topCircle,delta);
    translateY(resRightLeg.bottomCircle,delta);
    *Body=resBody,*leftArm=resLeftArm,*leftLeg=resLeftLeg,*rightArm=resRightArm,*rightLeg=resRightLeg;
}

void Person::bodyTranslateX(double delta)
{
    Cylinder resBody=*Body,resLeftArm=*leftArm,resRightArm=*rightArm,resLeftLeg=*leftLeg,resRightLeg=*rightLeg;
    translateX(resBody.topCircle,delta);
    translateX(resBody.bottomCircle,delta);
    translateX(resLeftArm.topCircle,delta);
    translateX(resLeftArm.bottomCircle,delta);
    translateX(resRightArm.topCircle,delta);
    translateX(resRightArm.bottomCircle,delta);
    translateX(resLeftLeg.topCircle,delta);
    translateX(resLeftLeg.bottomCircle,delta);
    translateX(resRightLeg.topCircle,delta);
    translateX(resRightLeg.bottomCircle,delta);
    *Body=resBody,*leftArm=resLeftArm,*leftLeg=resLeftLeg,*rightArm=resRightArm,*rightLeg=resRightLeg;
}




void Person::personKeyboardListener(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
            pos.y += 0.01;
            swingIndArm(3,0);
            swingIndArm(-3,0);
            break;
        case 's':
            pos.y -=0.01;
            swingIndArm(-3,0);
            swingIndLeg(3,0);
            break;
        case 'a':
            pos.x +=0.01;
            rotateIndLeftArm(90);
            rotateIndLeftLeg(90);
            rotateIndRightArm(90);
            rotateIndRightLeg(90);
            swingIndArm(3,0);
            swingIndLeg(-3,0);
            break;
        case 'd':
            pos.x -=0.01;
            rotateIndLeftArm(90);
            rotateIndLeftLeg(90);
            rotateIndRightArm(90);
            rotateIndRightLeg(90);
            swingIndArm(3,0);
            swingIndLeg(-3,0);
            break;


    
        default:
            break;
    }
}
void Person::move(double delx, double dely)
{

}

void Person::draw()
{
    head->render();
    Body->render();
    leftArm->render();
    rightArm->render();
    leftLeg->render();
    rightLeg->render();
}


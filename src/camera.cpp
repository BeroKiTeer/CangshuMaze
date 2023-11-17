#include "camera.h"

Camera::Camera():Listener(){}

void Camera::ShowTestCurb(int SmallMap)
{
    if(!get_TestCurbPoint().empty()) {
        reset_TestCurbPoint();
    }
    vector<Point>temp;
    for(int i = 0; i < 8; i++) {
        temp.push_back(Point(TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]));
    }
    set_TestCurbPoint(temp);
    temp.clear();
    vector<Point>Temp = get_TestCurbPoint();
    scaleEntirety(Temp,get_scale());
    set_TestCurbPoint(Temp);
    Temp.clear();
    Temp = get_TestCurbPoint();
    translate(Temp,get_TestCurbX(), get_TestCurbY(), get_TestCurbZ());
    set_TestCurbPoint(Temp);
    Temp.clear();
    // std::cout << this->get_TestCurbY() << std::endl;
    if(SmallMap == 1){
        SetCamera(
            get_TestCurbX(), get_TestCurbY(), get_TestCurbZ(), 
            get_CameraDistance(), get_TestCurbX()+0.04*get_scale(), get_TestCurbY()+0.04*get_scale(), 
            get_TestCurbZ()-0.04*get_scale(), get_angleY(), get_angleZ()
        );
    }
    Temp = get_TestCurbPoint();
    shaderTestCurb(Temp,SmallMap);
    set_TestCurbPoint(Temp);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<12; ++i) // 12 条线段
    {
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = get_TestCurbPoint()[TestCurbList[i][j]].x;
            GLfloat y = get_TestCurbPoint()[TestCurbList[i][j]].y;
            GLfloat z = get_TestCurbPoint()[TestCurbList[i][j]].z;
            glVertex3f(x*SmallMap,y,z);
        }
    }
    glEnd();
}

void Camera::shaderTestCurb(VP& TestCurbPoint, int SmallMap){
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 

    VP Surface;
    Surface.push_back(TestCurbPoint[0]);
    Surface.push_back(TestCurbPoint[1]);
    Surface.push_back(TestCurbPoint[2]);
    Surface.push_back(TestCurbPoint[3]);

    Surface.push_back(TestCurbPoint[0]);
    Surface.push_back(TestCurbPoint[4]);
    Surface.push_back(TestCurbPoint[7]);
    Surface.push_back(TestCurbPoint[3]);

    Surface.push_back(TestCurbPoint[0]);
    Surface.push_back(TestCurbPoint[4]);
    Surface.push_back(TestCurbPoint[5]);
    Surface.push_back(TestCurbPoint[1]);

    Surface.push_back(TestCurbPoint[6]);
    Surface.push_back(TestCurbPoint[2]);
    Surface.push_back(TestCurbPoint[3]);
    Surface.push_back(TestCurbPoint[7]);

    Surface.push_back(TestCurbPoint[6]);
    Surface.push_back(TestCurbPoint[7]);
    Surface.push_back(TestCurbPoint[4]);
    Surface.push_back(TestCurbPoint[5]);

    Surface.push_back(TestCurbPoint[6]);
    Surface.push_back(TestCurbPoint[5]);
    Surface.push_back(TestCurbPoint[1]);
    Surface.push_back(TestCurbPoint[2]);

    for(int i=0; i<24; i+=4)
    {

        glBindTexture(GL_TEXTURE_2D, get_TestCurbShaderID());
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(Surface[i].x*SmallMap, Surface[i].y, Surface[i].z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(Surface[i+1].x*SmallMap, Surface[i+1].y, Surface[i+1].z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(Surface[i+2].x*SmallMap, Surface[i+2].y, Surface[i+2].z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(Surface[i+3].x*SmallMap, Surface[i+3].y, Surface[i+3].z);
        glEnd();
    }
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}

void Camera::ShowCamera(){
    SetCamera(
        get_TestCurbX(), get_TestCurbY(), get_TestCurbZ(), 
        get_CameraDistance(), get_TestCurbX(), get_TestCurbY(), 
        get_TestCurbZ(), get_angleY(), get_angleZ()
    );
    std::cout << get_angleY() << " " << get_angleZ() << std::endl;
}

void Camera::Init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100.0);
}

void Camera::SetCamera(double x, double y, double z, double CameraDistance,
        double LookX, double LookY, double LookZ,
        double angleY, double angleZ){
    VP CameraPoint;
    // std::cout << x << " " << y << " " << z << std::endl;
    CameraPoint.push_back(Point(x-CameraDistance,y,z));
    //绕立方体旋转,绕y轴旋转 T1*T2*T1^(-1)

    translate(CameraPoint,-x,-y,-z);
    //先旋转x后旋转y，矩阵不满足交换律
    rotateDY(CameraPoint,angleY);
    rotateDZ(CameraPoint,angleZ);
    translate(CameraPoint,x,y,z);

    //设置视点
    gluLookAt (
        CameraPoint[0].x, CameraPoint[0].y, CameraPoint[0].z, //相机位置
        LookX, LookY, LookZ, //立方体所在的点                  //观察点位置
        0.0, 0.0, -1.0);
}
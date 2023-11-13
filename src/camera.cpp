#include "camera.h"

Camera::Camera()
{
    TestCurbX = 0.0; TestCurbY = 0.0; TestCurbZ=0.0;
    angleY = 15.0; angleZ=-90.0; CameraDistance = 1.0;
    LMouseDown = false, RMouseDown = false;
    LMouseDownX = 0, LMouseDownY = 0;
    DealyTime = 0;
    EnableCameraDistance = true;
    EnableCameraLastDistance = 1.0;
    TestCurbShaderID = 0;
}

void Camera::ShowTestCurb()
{
    if(!TestCurbPoint.empty())
        TestCurbPoint.clear();
    for(int i = 0; i < 8; i++){
        TestCurbPoint.push_back(Point(TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]));
    }
    scaleEntirety(TestCurbPoint,0.0625);
    translate(TestCurbPoint,TestCurbX, TestCurbY, TestCurbZ);
    getInstance()->SetCamera(
        TestCurbX, TestCurbY, TestCurbZ, 
        CameraDistance, TestCurbX+0.2*0.0625, TestCurbY+0.2*0.0625, 
        TestCurbZ-0.2*0.0625, angleY, angleZ
    );
    shaderTestCurb(TestCurbPoint);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<12; ++i) {       // 12 条线段
        for(int j=0; j<2; ++j) {    // 每条线段 2个顶点
            GLfloat x = TestCurbPoint[TestCurbList[i][j]].x;
            GLfloat y = TestCurbPoint[TestCurbList[i][j]].y;
            GLfloat z = TestCurbPoint[TestCurbList[i][j]].z;
            glVertex3f(x,y,z); 
        }
    }
    glEnd();
}

void Camera::shaderTestCurb(VP& TestCurbPoint)
{
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    if(TestCurbShaderID == 0){
        TestCurbShaderID = loadTexture("texture/TestCurb.bmp");
        if(TestCurbShaderID == 0){
            std::cerr << "图片加载失败" << std::endl;
            exit(0);
        }
    }

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

        glBindTexture(GL_TEXTURE_2D, TestCurbShaderID);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(Surface[i].x, Surface[i].y, Surface[i].z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(Surface[i+1].x, Surface[i+1].y, Surface[i+1].z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(Surface[i+2].x, Surface[i+2].y, Surface[i+2].z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(Surface[i+3].x, Surface[i+3].y, Surface[i+3].z);
        glEnd();
    }
    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}

void Camera::ShowCamera()
{
    getInstance()->SetCamera(
        TestCurbX, TestCurbY, TestCurbZ, 
        CameraDistance, TestCurbX, TestCurbY, 
        TestCurbZ, angleY, angleZ
    );
    // std::cout << angleY << " " << angleZ << std::endl;
}

void Camera::Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100.0);
}

void Camera::CameraKeyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'w':
            TestCurbY += 0.1;break;
        case 's':
            TestCurbY -= 0.1;break;
        case 'a':
            TestCurbX += 0.1;break;
        case 'd':
            TestCurbX -= 0.1;break;
        case 'q':
            TestCurbZ -= 0.1;break;
        case 'e':
            TestCurbZ += 0.1;break;
        default:
            break;
    }
}

void Camera::SetCamera(double x, double y, double z, double CameraDistance,
        double LookX, double LookY, double LookZ,
        double angleY, double angleZ)
{
    VP CameraPoint;
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

void Camera::CameraMouseClick(int btu, int state, int x, int y)
{
    if(btu == GLUT_WHEEL_UP){
        if(EnableCameraDistance)
            if(CameraDistance > 0.15)
                CameraDistance -= 0.01;
    }
    if(btu == GLUT_WHEEL_DOWN){
        if(EnableCameraDistance)
            CameraDistance += 0.01;
    }
    if(btu == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        LMouseDown = true;
        LMouseDownX = x, LMouseDownY = y;
    }
    if(btu == GLUT_LEFT_BUTTON && state == GLUT_UP){
        LMouseDown = false;
        DealyTime = 0;
        LMouseDownX = 0, LMouseDownY = 0;
    }
    if(btu == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        RMouseDown = true;
    }
    if(btu == GLUT_RIGHT_BUTTON && state == GLUT_UP){
        RMouseDown = false;
    }
}

void Camera::CameraMotion(int x, int y)
{
    if(LMouseDown){
        double dx = LMouseDownX - x;
        double dy = LMouseDownY - y;
        angleY = angleY - dy/10;
        angleZ = angleZ + dx/10;
        LMouseDownX = x;
        LMouseDownY = y;
    }
}
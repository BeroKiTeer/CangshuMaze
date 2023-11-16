#include "camera.h"

Camera::Camera()
{
    TestCurbX = 0.0; TestCurbY = 0.0; TestCurbZ=0.0;
    set_angleY(15.0); set_angleZ(-90.0); set_CameraDistance(1.0);
    set_LMouseDown(false), set_RMouseDown(false);
    set_LMouseDownX(0), set_LMouseDownY(0);
    set_DealyTime(0);
    set_EnableCameraDistance(true);
    set_EnableCameraLastDistance(1.0);
    TestCurbShaderID = TextureWallID;
    scale = 0.4;
}

void Camera::ShowTestCurb(int SmallMap)
{
    if(!TestCurbPoint.empty())
        TestCurbPoint.clear();
    for(int i = 0; i < 8; i++){
        TestCurbPoint.push_back(Point(TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]));
    }
    scaleEntirety(TestCurbPoint,scale);
    translate(get_TestCurbPoint(),get_TestCurbX(), get_TestCurbY(), get_TestCurbZ());
    if(SmallMap == 1){
        getInstance()->SetCamera(
            get_TestCurbX(), get_TestCurbY(), get_TestCurbZ(), 
            get_CameraDistance(), TestCurbX+0.2*get_scale(), get_TestCurbY()+0.2*get_scale(), 
            get_TestCurbZ()-0.2*get_scale(), get_angleY(), get_angleZ()
        );
    }
    shaderTestCurb(TestCurbPoint,SmallMap);
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for(int i=0; i<12; ++i) // 12 条线段
    {
        for(int j=0; j<2; ++j) // 每条线段 2个顶点
        {
            GLfloat x = TestCurbPoint[TestCurbList[i][j]].x;
            GLfloat y = TestCurbPoint[TestCurbList[i][j]].y;
            GLfloat z = TestCurbPoint[TestCurbList[i][j]].z;
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

        glBindTexture(GL_TEXTURE_2D, TestCurbShaderID);
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
    getInstance()->SetCamera(
        TestCurbX, TestCurbY, TestCurbZ, 
        get_CameraDistance(), TestCurbX, TestCurbY, 
        TestCurbZ, get_angleY(), get_angleZ()
    );
    // std::cout << angleY << " " << angleZ << std::endl;
}

void Camera::Init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100.0);
}

// void Camera::CameraKeyboard(unsigned char key, int x, int y){
//     switch(key){
//         case 'w':
//             TestCurbY += 0.05;break;
//         case 's':
//             TestCurbY -= 0.05;break;
//         case 'a':
//             TestCurbX += 0.05;break;
//         case 'd':
//             TestCurbX -= 0.05;break;
//         case 'q':
//             TestCurbZ -= 0.05;break;
//         case 'e':
//             TestCurbZ += 0.05;break;
//         default:
//             break;
//     }
// }

void Camera::SetCamera(double x, double y, double z, double CameraDistance,
        double LookX, double LookY, double LookZ,
        double angleY, double angleZ){
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

void Camera::CameraMouseClick(int btu, int state, int x, int y){
    if(btu == GLUT_WHEEL_UP){
        if(get_EnableCameraDistance())
            if(get_CameraDistance() > 0.15)
                set_CameraDistance(get_CameraDistance()-0.1);
    }
    if(btu == GLUT_WHEEL_DOWN){
        if(get_EnableCameraDistance())
            set_CameraDistance(get_CameraDistance()+0.1);
    }
    if(btu == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        set_LMouseDown(true);
        set_LMouseDownX(x), set_LMouseDownY(y);
    }
    if(btu == GLUT_LEFT_BUTTON && state == GLUT_UP){
        set_LMouseDown(false);
        set_DealyTime(0);
        set_LMouseDownX(0), set_LMouseDownY(0);
    }
    if(btu == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        set_RMouseDown(true);
    }
    if(btu == GLUT_RIGHT_BUTTON && state == GLUT_UP){
        set_RMouseDown(false);
    }
}

void Camera::CameraMotion(int x, int y){
    if(get_LMouseDown()){
        double dx = get_LMouseDownX() - x;
        double dy = get_LMouseDownY() - y;
        set_angleY(get_angleY() - dy/10);
        set_angleZ(get_angleZ() + dx/10);
        set_LMouseDownX(x);
        set_LMouseDownY(y);
    }
}
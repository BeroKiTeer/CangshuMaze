#include "camera.h"

void Camera::ShowTestCurb(int SmallMap){
    if(!TestCurbPoint.empty())
        TestCurbPoint.clear();
    for(int i = 0; i < 8; i++){
        TestCurbPoint.push_back(Point(TestCurb[i][0],TestCurb[i][1],TestCurb[i][2]));
    }
    scaleEntirety(TestCurbPoint,scale);
    translate(TestCurbPoint,TestCurbX, TestCurbY, TestCurbZ);
    if(SmallMap == 1){
        getInstance()->SetCamera(
            TestCurbX, TestCurbY, TestCurbZ, 
            CameraDistance, TestCurbX + 0.04*scale, TestCurbY + 0.04*scale, 
            TestCurbZ-0.04*scale, angleY, angleZ
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

OrientWASD Camera::CanMove(
    const RandomWallXOY& wall, const Point2d& point, 
    double Longx, double Longy
){
    double leftUpX = point.x + Longx, leftUpY = point.y + Longy;
    double leftDownX = point.x + Longx, leftDownY = point.y;
    double RightUpX = point.x, RightUpY = point.y + Longy;
    double RightDownX = point.x, RightDownY = point.y;
    
    OrientWASD ret;
    vector<OrientWASD> tWASD;

    for(auto i : wall.VWall){
        //wall是渲染层面是叠加，因此要去重相同的

        //左上角检测
        if(i.DrawX < leftUpX && leftUpX < i.DrawX + i.LongX && 
           i.DrawY < leftUpY && leftUpY < i.DrawY + i.LongY
        ){
            // std::cout << "LeftUp" << std::endl;
            ret.Up = false;
            ret.Left = false;
            tWASD.push_back(OrientWASD(false,true,false,true,i));

        }
        //左下角检测
        if(i.DrawX < leftDownX && leftDownX < i.DrawX + i.LongX && 
           i.DrawY < leftDownY && leftDownY < i.DrawY + i.LongY
        ){
            // std::cout << "LeftDown" << std::endl;
            ret.Down = false;
            ret.Left = false;
            tWASD.push_back(OrientWASD(true,false,false,true,i));
        }
        //右上角检测
        if(i.DrawX < RightUpX && RightUpX < i.DrawX + i.LongX && 
           i.DrawY < RightUpY && RightUpY < i.DrawY + i.LongY
        ){
            // std::cout << "RightUp" << std::endl;
            ret.Right = false;
            ret.Up = false;
            tWASD.push_back(OrientWASD(false,true,true,false,i));
        }
        //右下角检测
        if(i.DrawX < RightDownX && RightDownX < i.DrawX + i.LongX && 
           i.DrawY < RightDownY && RightDownY < i.DrawY + i.LongY
        ){
            // std::cout << "RightDown" << std::endl;
            ret.Down = false;
            ret.Right = false;
            tWASD.push_back(OrientWASD(true,false,true,false,i));
        }
    }

    if(tWASD.empty()){
        return OrientWASD();
    }
    
    //查找那个节点是重复的
    std::cout << "--------------------" << std::endl;
    for(auto i : tWASD){
        i.GetInfo();
    }
    OrientWASD Duplicate;
    for(int i = 0; i < tWASD.size(); ++i){
        for(int j = i+1; j < tWASD.size(); ++j){
            if(tWASD[i] == tWASD[j]){
                Duplicate = tWASD[i];
                break;
            }
        }
    }
    for(int i = 0; i < tWASD.size(); ++i){
        if(Duplicate == tWASD[i]){
            tWASD.erase(tWASD.begin() + i);
            i = -1;
        }
    }
    std::cout << "********************" << std::endl;
    std::cout << "DuplicatePoint ";
    Duplicate.GetInfo();
    std::cout << std::endl;
    for(auto i : tWASD){
        i.GetInfo();
    }
    std::cout << "--------------------" << std::endl;

    if(
        (!(Duplicate == OrientWASD()) && tWASD.size() == 0) ||
        //一点嵌入的嵌入点是重复点  
        //或
        //一点嵌入的嵌入点不是重复点
        (tWASD.size() == 1 && Duplicate == OrientWASD())
    )
    {
        std::cout << "1 Point" << std::endl;
        WallXOY EmbadSingleWall;
        if( (!(Duplicate == OrientWASD()) && tWASD.size() == 0) ){
            EmbadSingleWall = Duplicate.wall;
        }
        else{
            EmbadSingleWall = tWASD[0].wall;
        }
        //看看一点嵌入那个嵌入的多，就向哪里前进
        //左上
        if(tWASD[0] == OrientWASD(0,1,0,1)){
            double LongX = leftUpX - EmbadSingleWall.DrawX;
            double LongY = leftUpY - EmbadSingleWall.DrawY;
            if(LongX > LongY){
                return OrientWASD(0,1,1,1);
            }
            else{
                return OrientWASD(1,1,0,1);
            }
        }

        //左下
        if(tWASD[0] == OrientWASD(1,0,0,1)){
            double LongX = leftDownX - EmbadSingleWall.DrawX;
            double LongY = (EmbadSingleWall.DrawY + EmbadSingleWall.LongY) - leftDownY;
            if(LongX > LongY){
                return OrientWASD(1,0,1,1);
            }
            else{
                return OrientWASD(1,1,0,1);
            }
        }

        //右上
        if(tWASD[0] == OrientWASD(0,1,1,0)){
            double LongX = (EmbadSingleWall.DrawX + EmbadSingleWall.LongX) - RightUpX;
            double LongY = RightUpY - EmbadSingleWall.DrawY;
            if(LongX > LongY){
                return OrientWASD(0,1,1,1);
            }
            else{
                return OrientWASD(1,1,1,0);
            }
        }

        //右下
        if(tWASD[0] == OrientWASD(1,0,1,0)){
            double LongX = (EmbadSingleWall.DrawX + EmbadSingleWall.LongX) - RightDownX;
            double LongY = (EmbadSingleWall.DrawY + EmbadSingleWall.LongY) - RightDownY;
            if(LongX > LongY){
                return OrientWASD(1,0,1,1);
            }
            else{
                return OrientWASD(1,1,1,0);
            }
        }
    }


    if(
        ( tWASD.size() == 1 && !(Duplicate == OrientWASD(1,1,1,1)) ) ||
        ( tWASD.size() == 2 && Duplicate == OrientWASD(1,1,1,1))
    ){ 
        std::cout << "2 Point" << std::endl;
        if(tWASD.size() == 1 && !(Duplicate == OrientWASD(1,1,1,1))){
            return Duplicate | tWASD[0];
        }
        else{
            return tWASD[0] | tWASD[1];
        }
    }

    //三点不同一定不会出现
    if(tWASD.size() == 2 && !(Duplicate == OrientWASD(1,1,1,1))){
        std::cout << "3 Point" << std::endl;
        OrientWASD t1 = Duplicate | tWASD[0];
        OrientWASD t2 = Duplicate | tWASD[1];
        OrientWASD t3 = t1 & t2;
        return t3;
    }

    // DuplicatePoint RightDown
    // LeftDown
    // LeftDown
    // LeftDown
    // 上述情况是 丁字形状况(三个墙面叠加在一起，立方体都在这三个墙中)
    
    if(tWASD.size() == 3){
        std::cout << "4 Point <-> Three Wall" << std::endl;
        return Duplicate | tWASD[0];
    }
    // static bool ErrorMessageBox = true;
    // if(ErrorMessageBox){
        MessageBox(NULL,TEXT("The Function of bumping check:\nunexpected size of tWASD"),
                   TEXT("ERROR"),MB_OK | MB_ICONERROR);
        // ErrorMessageBox = false;
    // }
}

void Camera::ShowCamera(){
    getInstance()->SetCamera(
        TestCurbX, TestCurbY, TestCurbZ, 
        CameraDistance, TestCurbX, TestCurbY, 
        TestCurbZ, angleY, angleZ
    );
    // std::cout << angleY << " " << angleZ << std::endl;
}

void Camera::Init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 0.1, 100.0);
}

void Camera::CameraKeyboard(unsigned char key, int x, int y){
    double TestCurbLong = getTestCurbLong();
    OrientWASD orient = CanMove(wall,Point2d(TestCurbX,TestCurbY), TestCurbLong,TestCurbLong);

    switch(key){
        case 'w':
            if(orient.Up)
                TestCurbY += 0.01;
            break;
        case 's':
            if(orient.Down)
                TestCurbY -= 0.01;
            break;
        case 'a':
            if(orient.Left)
                TestCurbX += 0.01;
            break;
        case 'd':
            if(orient.Right)
                TestCurbX -= 0.01;
            break;
        case 'q':
            TestCurbZ -= 0.05;break;
        case 'e':
            TestCurbZ += 0.05;break;
        default:
            break;
    }
}

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
        if(EnableCameraDistance)
            if(CameraDistance > 0.15)
                CameraDistance -= 0.1;
    }
    if(btu == GLUT_WHEEL_DOWN){
        if(EnableCameraDistance)
            CameraDistance += 0.1;
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

void Camera::CameraMotion(int x, int y){
    if(LMouseDown){
        double dx = LMouseDownX - x;
        double dy = LMouseDownY - y;
        angleY = angleY - dy/10;
        angleZ = angleZ + dx/10;
        LMouseDownX = x;
        LMouseDownY = y;
    }
}
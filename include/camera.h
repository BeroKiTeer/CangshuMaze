#pragma once
#include "GL/gl.h"
#include <vector>

struct Point;

class Camera{
public:
    Camera() = default;
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat targetX, GLfloat targetY, GLfloat targetZ);
    ~Camera() = default;

    void setPosition(GLfloat posX, GLfloat posY, GLfloat posZ);//设置位置
    void setTarget(GLfloat targetX, GLfloat targetY, GLfloat targetZ);//设置目标
    void setUpVector(GLfloat upX, GLfloat upY, GLfloat upZ);//设置向量
    void updateViewMatrix();        //根据相机位置更新渲染视图
    void setProjectionMatrix(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane);//设置项目矩阵
    void rotate(GLfloat deltaYaw, GLfloat deltaPitch);//旋转
    void move(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ);//前后左右
    GLfloat* GetViewMatrix();

    void firstPerson();//第一人称视角
    void ThirdPerson();//第三人称视角

private:
    std::vector<GLfloat>camaraPosition;   //相机位置
    std::vector<GLfloat>lookatPoint;      //观察向量（相机朝向）
    std::vector<GLfloat>upVector;         //相机的上方向
    std::vector<GLfloat>viewMatrix;       //观察矩阵
    std::vector<GLfloat>projectionMatrix; //投影矩阵
};
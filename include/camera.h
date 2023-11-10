#pragma once
#include "GL/gl.h"
#include "config.h"
#include <vector>

class Camera{
public:
    Camera() = default;
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat targetX, GLfloat targetY, GLfloat targetZ);
    ~Camera() = default;

    void setPosition(GLfloat posX, GLfloat posY, GLfloat posZ);
    void setTarget(GLfloat targetX, GLfloat targetY, GLfloat targetZ);
    void setUpVector(GLfloat upX, GLfloat upY, GLfloat upZ);
    void updateViewMatrix();        //根据相机位置更新渲染视图
    void setProjectionMatrix(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane);
    void rotate(GLfloat deltaYaw, GLfloat deltaPitch);
    void move(GLfloat deltaX, GLfloat deltaY, GLfloat deltaZ);
    GLfloat* GetViewMatrix();

    void firstPerson();//第一人称视角
    void ThirdPerson();//第三人称视角

private:
    Point camaraPosition;   //相机位置
    Point lookatPoint;      //观察向量（相机朝向）
    Point upVector;         //相机的上方向
    std::vector<Point>viewMatrix;       //观察矩阵
};
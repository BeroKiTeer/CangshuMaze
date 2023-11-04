#pragma once
#include <gl/gl.h>
class CollisionBox {
public:
    // 构造函数
    CollisionBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ);

    // 设置碰撞盒的最小和最大坐标
    void SetBounds(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ);

    // 获取碰撞盒的最小坐标
    GLfloat GetMinX() const;
    GLfloat GetMinY() const;
    GLfloat GetMinZ() const;

    // 获取碰撞盒的最大坐标
    GLfloat GetMaxX() const;
    GLfloat GetMaxY() const;
    GLfloat GetMaxZ() const;

    // 碰撞检测：检查两个碰撞盒是否相交
    bool CheckCollision(const CollisionBox& otherBox) const;

private:
    GLfloat minBounds[3]; // 最小坐标
    GLfloat maxBounds[3]; // 最大坐标
};
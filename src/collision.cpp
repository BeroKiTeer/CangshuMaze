#include "collision.h"

CollisionBox::CollisionBox(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ) {
    SetBounds(minX, minY, minZ, maxX, maxY, maxZ);
}

void CollisionBox::SetBounds(GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat maxX, GLfloat maxY, GLfloat maxZ) {
    minBounds[0] = minX;
    minBounds[1] = minY;
    minBounds[2] = minZ;

    maxBounds[0] = maxX;
    maxBounds[1] = maxY;
    maxBounds[2] = maxZ;
}

GLfloat CollisionBox::GetMinX() const {
    return minBounds[0];
}

GLfloat CollisionBox::GetMinY() const {
    return minBounds[1];
}

GLfloat CollisionBox::GetMinZ() const {
    return minBounds[2];
}

GLfloat CollisionBox::GetMaxX() const {
    return maxBounds[0];
}

GLfloat CollisionBox::GetMaxY() const {
    return maxBounds[1];
}

GLfloat CollisionBox::GetMaxZ() const {
    return maxBounds[2];
}

bool CollisionBox::CheckCollision(const CollisionBox& otherBox) const {
    // 检查两个碰撞盒是否相交
    if (maxBounds[0] < otherBox.GetMinX() || minBounds[0] > otherBox.GetMaxX()) {
        return false; // 两个盒子在X轴上没有交集
    }
    if (maxBounds[1] < otherBox.GetMinY() || minBounds[1] > otherBox.GetMaxY()) {
        return false; // 两个盒子在Y轴上没有交集
    }
    if (maxBounds[2] < otherBox.GetMinZ() || minBounds[2] > otherBox.GetMaxZ()) {
        return false; // 两个盒子在Z轴上没有交集
    }
    return true; // 两个盒子相交
}
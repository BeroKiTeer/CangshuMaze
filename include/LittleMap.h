#pragma once
#include <vector>
#include <gl/gl.h>

class LittleMap {
public:
    void init(const char* texturePath, int width, int height);    //初始化小地图
    void updateMap(int playerX, int playerY, int targetX, int targetY); //更新小地图
    void render();          //绘制小地图
    void SetPlayerPosition(int x, int y);   //设置玩家位置
    void DrawTargetPosition(int x, int y);  //绘制目标位置
    void ClearMap();        //清空小地图

private:
    GLuint mapTexture;      //贴图
    int playerX, playerY;   // 玩家位置
    int targetX, targetY;   // 目标位置
    int mapWidth, mapHeight;//小地图宽度和高度
};
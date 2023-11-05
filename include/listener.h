#pragma once
/**
 * keyboardListener 
 * mouseListener
 */
#include <vector>

class Listener {
public:
    Listener() = default;
    ~Listener() = default;

    //下面是OpenGL的回调函数
    void mouseClick(int button, int state, int x, int y);
    //button：表示用户按下或释放的鼠标按钮，通常为常量，如 GLUT_LEFT_BUTTON、GLUT_RIGHT_BUTTON 等。
    //state：表示按钮的状态，通常为 GLUT_DOWN（按下）或 GLUT_UP（释放）
    //x,y表示鼠标点击事件发生的窗口内的坐标位置。
    void mouseClickMove(int x, int y);
    //x 和 y：表示鼠标当前的坐标位置。
    void mouseInMove(int x,int y);
    //x：表示鼠标当前的水平坐标位置，y：表示鼠标当前的垂直坐标位置
    void keyboardListener(unsigned char key, int x, int y);
    //key：表示用户按下的键的ASCII字符。x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    void specialListener(int key, int x, int y);
    //key：表示用户按下的特殊键，通常为常量，如方向键（GLUT_KEY_LEFT、GLUT_KEY_RIGHT等）。
    //x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    void specialUpListener(int key, int x, int y);
    //key：表示用户释放的特殊键，通常为常量，如方向键（GLUT_KEY_LEFT、GLUT_KEY_RIGHT等）。
    //x 和 y：表示特殊键事件发生的窗口内的坐标位置。
    void windowFoucusListener(int state);
    //state：表示窗口获取或失去焦点的状态，GLUT_LEFT（失去焦点）或 GLUT_ENTERED（获取焦点）。
};
#include "listener.h"

void Listener::keyBoardsListener(unsigned char key, int x, int y){
    switch(key){
        case '1':
            IsThirdPeople = false;
            break;
        case '3':
            IsThirdPeople = true;
            break;
        default: 
            break;
    }
    Camera::OCameraKeyboard(key,x,y);
}
void Listener::mouseClick(int button, int state, int x, int y){
    Camera::OCameraMouseClick(button,state,x,y);
}
void Listener::mouseMotionListener(int x, int y){
    Camera::OCameraMotion(x,y);
}

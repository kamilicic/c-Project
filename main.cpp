#include <iostream>
#include "GameEngine/GameEngine.h"
int main() {
    //std::cout << "Welcome in this game!" << std::endl;
    GameEngine *ge = new GameEngine();
    ge->play();
    delete ge;
    return 0;
}

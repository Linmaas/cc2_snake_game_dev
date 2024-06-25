#pragma once

#include "ofMain.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();

    // int foo = 6;

    


    
    int cellSize = 50;

    

    void updateSnake();
    void drawSnake();
    void setDir(int x, int y);
    bool eat(ofVec2f foodPos);

    

private:
    float xSpeed;
    float ySpeed;

    ofVec2f myPos{ 0,0 };
    ofColor colorIO;

};

#pragma once

#include "ofMain.h"


class ofFood {
    
public:

    ofFood();
    ~ofFood();

    int scl = 50;
    
    
    ofVec2f myPos{};

    void pickLocation();
    void drawFood();

private:

    ofColor color;
  


};

#pragma once

#include "ofMain.h"
#include "ofConfig.h"


class ofFood {
    
public:

    ofFood();
    ~ofFood();

    int gridSize = ofConfig::GridSize;
    
    
    ofColor color;
    ofVec2f myPos{};

    void pickLocation();
    void drawFood();


};

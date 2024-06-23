#pragma once

#include "ofMain.h"
#include "ofConfig.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();
    
    int gridSize = ofConfig::GridSize;

    std::vector<ofVec2f> body;  // Vector to hold the segments of the snake's body
        int xSpeed, ySpeed;
        ofColor color;
        
        void updateSnake();
        void drawSnake();
        void setDir(int x, int y);
        bool eat(ofVec2f foodPos);
        void grow();
    
    ofImage segmentImage;  // Image for the snake segment
    
private:
    void loadSegmentImage();  // Function to load the image

};

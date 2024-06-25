#pragma once

#include "ofMain.h"
#include "ofConfig.h"


class ofSnake {

public:

    ofSnake();
    ~ofSnake();
    
    int gridSize = ofConfig::GridSize  ;

    std::vector<ofVec2f> body;  // Vector to hold the segments of the snake's body
        int xSpeed, ySpeed;
        ofColor color;
        
        void updateSnake();
        void drawSnake();
        void setDir(int x, int y);
        bool eat(ofVec2f foodPos);
        void grow();
        bool checkSelfCollision();  // Check if the snake collides with itself

    
    std::vector<ofImage> segmentImages;  // Vector to hold the images for animation
        int currentFrame;  // Current frame in the animation sequence
        float frameDuration;  // Duration for each frame
        float lastFrameTime;  // Time when the last frame was updated

    private:
        void loadSegmentImages();  // Function to load the images

};

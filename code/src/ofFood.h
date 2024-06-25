#pragma once

#include "ofMain.h"
#include "ofConfig.h"


class ofFood {
    
public:

    ofFood();
    ~ofFood();

    int gridSize = ofConfig::GridSize  ;
    
    
    ofColor color;
    ofVec2f myPos{};
    
    
    void pickLocation();
    void drawFood();
    //void loadFoodImages();  // Function to load the images
    
    
    
    
private:
    

        std::vector<ofImage> foodImages;  // Vector to hold multiple food images
        ofImage currentFoodImage;  // Current food image

        void loadFoodImages();  // Load all food images
        void selectRandomFoodImage();  // Select a random food image
    ofImage FoodImage;

};

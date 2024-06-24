#include "ofFood.h"
#include "ofConfig.h"


ofFood::ofFood() {
    
    color.set(250, 0, 50);
    
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
    
    // Load all food images
        loadFoodImages();

}

ofFood::~ofFood() {

}


void ofFood::loadFoodImages() {
    // Food Images
    std::vector<std::string> imageFiles = {"berry_1.png", "berry_2.png"};

        for (const auto& file : imageFiles) {
            ofImage img;
            if (img.load(file)) {
                foodImages.push_back(img);
                ofLogNotice() << "Loaded image: " << file;
            } else {
                ofLogError() << "Failed to load image: " << file;
            }
        }
    
    // Check if images are loaded
       if (foodImages.empty()) {
           ofLogError() << "No food images were loaded!";
       } else {
           ofLogNotice() << foodImages.size() << " food images were loaded successfully.";
       }
}


void ofFood::selectRandomFoodImage() {
    if (!foodImages.empty()) {
            int index = static_cast<int>(ofRandom(0, foodImages.size()));
            currentFoodImage = foodImages[index];
            ofLogNotice() << "Selected image index: " << index << " (" << currentFoodImage.getWidth() << "x" << currentFoodImage.getHeight() << ")";
        } else {
            ofLogError() << "No images loaded to select from!";
        }
}

void ofFood::pickLocation() {

    int cols = floor(ofGetWidth() / gridSize);
    int rows = floor(ofGetHeight() / gridSize);

    myPos.x = floor(ofRandom(cols))* gridSize;
    myPos.y = floor(ofRandom(rows))* gridSize;

    cout << "PICKED " << myPos.x << endl;
    
    selectRandomFoodImage();
}




void ofFood::drawFood() {
    
    //FoodImage.load("berry_1.png");
    //ofSetColor(color);
    //ofDrawRectangle(myPos.x,myPos.y, gridSize, gridSize);
    // Reset color to white before drawing the background image
       ofSetColor(255);
       
       // Disable blending if the image has an alpha channel
       //ofDisableAlphaBlending();
    
    // Check if the current food image is allocated before drawing
       if (currentFoodImage.isAllocated()) {
           currentFoodImage.draw(myPos.x, myPos.y, gridSize, gridSize);
       } else {
           ofLogError() << "Attempted to draw an unallocated image!";
       }

       // Enable blending again if you need it for other drawings
       //ofEnableAlphaBlending();
    
}


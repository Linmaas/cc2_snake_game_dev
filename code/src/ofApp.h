#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"
#include "ofConfig.h"


// TODO: Refactoring
// This class works but does not follow the best
// code design approach if you think of separating
// interface from implementation and access levels.
// Review all classes and improve the respective
// implementations accordingly.


class ofApp : public ofBaseApp{

	public:
	
		void setup();
		void update();
		void draw();


		void keyPressed(int key);
		
    ofImage backgroundImage;
    ofSnake mySnake{};
    ofFood myFood{};

	

    
    bool gameOver;  // Flag to indicate if the game is over
    
    ofTrueTypeFont gameOverFont;  // Font for the "Game Over" text

    
private:
    void loadBackgroundImage();  // Function to load the image

    
};

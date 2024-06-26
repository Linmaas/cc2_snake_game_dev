#pragma once

#include "ofMain.h"
#include "ofSnake.h"
#include "ofFood.h"
#include "ofConfig.h"
#include "ofUI.h"


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
        void mousePressed(int x, int y, int button);
		
    ofImage backgroundImage;
    ofSnake mySnake{};
    ofFood myFood{};
    ofUI myUI{};
    
    
    bool isMouseOver(float mouseX, float mouseY, float x, float y, float width, float height);
	

    
    bool gameOver;  // Flag to indicate if the game is over
    
    ofTrueTypeFont gameOverFont;  // Font for the "Game Over" text

    void resetGame();  // Function to reset the game (snake and food positions, etc.

    
private:
    void loadBackgroundImage();  // Function to load the image

    
};

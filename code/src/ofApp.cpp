#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(10);
    backgroundImage.load("piknik_2.png");
    gameOver = false;  // Initialize the gameOver flag
    // Load the font with size 32
    gameOverFont.load("ants.ttf", 80);
    
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
    if (gameOver) return;  // Skip update if game is over
    mySnake.updateSnake();
        if (mySnake.eat(myFood.myPos)) {
            myFood.pickLocation();
            mySnake.grow();
            std::cout << "Snake has grown." << std::endl;
        }
    
    // Check for self-collision to end the game
        if (mySnake.checkSelfCollision()) {
            gameOver = true;
            ofLogNotice() << "Game Over!";
        }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Reset color to white before drawing the background image
       ofSetColor(255);
       
       // Disable blending if the image has an alpha channel
       ofDisableAlphaBlending();

       // Draw the background image
       backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());

       // Enable blending again if you need it for other drawings
       ofEnableAlphaBlending();
	mySnake.drawSnake();
	myFood.drawFood();
    
    if (gameOver) {
            
        ofBackground(255, 255, 255);
            ofSetColor(0, 0, 0);
            std::string gameOverText = "Game Over";
            float textWidth = gameOverFont.stringWidth(gameOverText);
            float textHeight = gameOverFont.stringHeight(gameOverText);
            gameOverFont.drawString(gameOverText, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 + textHeight / 2);
    
        }
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (gameOver) return;  // Prevent direction change if game is over

	
	switch (key) {

	case OF_KEY_LEFT: // left
		mySnake.setDir(-1, 0);
		break;
	case OF_KEY_RIGHT: // right
		mySnake.setDir(1, 0);
		break;
	case OF_KEY_UP: // up
		mySnake.setDir(0, -1);
		break;
	case OF_KEY_DOWN: // down
		mySnake.setDir(0, 1);
		break;
	}
}







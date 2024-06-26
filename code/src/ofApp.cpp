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
            
        myUI.GameOverScreen(gameOverFont, gameOver);
        myUI.PlayAgainButton(gameOver);    
    
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

void ofApp::mousePressed(int x, int y, int button) {
    if (gameOver) {
        float buttonWidth = 200;
        float buttonHeight = 50;
        float buttonX = ofGetWidth() / 2 - buttonWidth / 2; ;
        float buttonY = ofGetHeight() / 2 - buttonHeight / 2 + 200;
        if(isMouseOver(x, y, buttonX, buttonY, buttonWidth, buttonHeight)) {
            resetGame();
        }
    }
}

void ofApp::resetGame() {
    gameOver = false;
    mySnake.resetSnake();
    myFood.pickLocation();
}

bool ofApp::isMouseOver(float mouseX, float mouseY, float x, float y, float width, float height) {
    return mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height;
}





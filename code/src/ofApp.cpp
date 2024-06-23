#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // TODO: Play with the frame rate to find a good handling.
    // Yet, think about this approach? What are the pros and cons
    // of using the frame rate and what other approach could be
    // used instead?
	ofSetFrameRate(10);
    
	ofBackground(255,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
    mySnake.updateSnake();
        if (mySnake.eat(myFood.myPos)) {
            myFood.pickLocation();
            mySnake.grow();
            std::cout << "Snake has grown." << std::endl;
        }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
	mySnake.drawSnake();
	myFood.drawFood();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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







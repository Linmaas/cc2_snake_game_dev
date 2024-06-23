#include "ofFood.h"
#include "ofConfig.h"


ofFood::ofFood() {
    
    color.set(250, 0, 50);
    
    // set the first position of food randomly
    // otherwise food and snake have the same pos at (0,0) which leads to an error
    // in "snake's eat function > startcheck is increased w/o reason"
    pickLocation();
}

ofFood::~ofFood() {

}


void ofFood::pickLocation() {

    int cols = floor(ofGetWidth() / gridSize);
    int rows = floor(ofGetHeight() / gridSize);

    myPos.x = floor(ofRandom(cols))* gridSize;
    myPos.y = floor(ofRandom(rows))* gridSize;

    cout << "PICKED " << myPos.x << endl;
}


void ofFood::drawFood() {
    
    ofSetColor(color);
    ofDrawRectangle(myPos.x,myPos.y, gridSize, gridSize);
}


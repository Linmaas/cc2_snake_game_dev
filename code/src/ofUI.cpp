#include "ofUI.h"

// game over screen function
void ofUI::GameOverScreen(ofTrueTypeFont& gameOverFont, bool gameOver){
    ofBackground(255, 255, 255);
            ofSetColor(0, 0, 0);
            std::string gameOverText = "Game Over";
            float textWidth = gameOverFont.stringWidth(gameOverText);
            float textHeight = gameOverFont.stringHeight(gameOverText);
            gameOverFont.drawString(gameOverText, ofGetWidth() / 2 - textWidth / 2, ofGetHeight() / 2 + textHeight / 2);

}

// start again button 

void ofUI::PlayAgainButton(bool gameOver){
    float buttonWidth = 200;
    float buttonHeight = 50;
    float buttonX = ofGetWidth() / 2 - buttonWidth / 2 ;
    float buttonY = ofGetHeight() / 2 - buttonHeight / 2 + 200;
    ofSetColor(0, 0, 0);
    ofDrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Play Again", buttonX + buttonWidth / 2 - 30 , buttonY + buttonHeight / 2 + 5);
}

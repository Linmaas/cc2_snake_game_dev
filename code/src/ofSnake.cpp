#include "ofSnake.h"
#include "ofConfig.h"

// test

ofSnake::ofSnake()
{

    body.push_back(ofVec2f(100, 100));  // Start with one segment at position (100, 100)
        xSpeed = 0;  // Initial speed is zero
        ySpeed = 0;
        color.set(255);  // Color white
}

ofSnake::~ofSnake()
{

    int test = 4;
    std::cout << "help, I will die" << std::endl;
}

void ofSnake::updateSnake()
{
    // First update all segments
      for (int i = body.size() - 1; i > 0; i--) {
          body[i] = body[i - 1];
      }
      // Update the head position based on current direction
      body[0].x += xSpeed * gridSize;
      body[0].y += ySpeed * gridSize;

      // Screen wrapping logic
      if (body[0].x >= ofGetWidth()) {  // If snake goes past the right edge
          body[0].x = 0;  // Wrap around to the left edge
      } else if (body[0].x < 0) {  // If snake goes past the left edge
          body[0].x = ofGetWidth() - gridSize;  // Wrap around to the right edge
      }

      if (body[0].y >= ofGetHeight()) {  // If snake goes past the bottom edge
          body[0].y = 0;  // Wrap around to the top edge
      } else if (body[0].y < 0) {  // If snake goes past the top edge
          body[0].y = ofGetHeight() - gridSize;  // Wrap around to the bottom edge
      }
}

void ofSnake::drawSnake()
{

    ofSetColor(color);
     for (auto& segment : body) {
         ofDrawRectangle(segment.x, segment.y, gridSize, gridSize);  // Draw each segment as a rectangle
     }
}

void ofSnake::setDir(int x, int y)
{

    xSpeed = x;
    ySpeed = y;
}

void ofSnake::grow() {
    if (!body.empty()) {
            ofVec2f newSegment = body.back();
            newSegment.x -= xSpeed * gridSize;
            newSegment.y -= ySpeed * gridSize;
            body.push_back(newSegment);
            std::cout << "New segment added. Total segments: " << body.size() << std::endl;
        }
}

bool ofSnake::eat(ofVec2f foodPos)
{
    if (body.empty()) return false;  // Safeguard if the body vector is somehow empty

        // Use body[0] as the position of the snake's head
        if (body[0].distance(foodPos) < gridSize) {
            std::cout << "eat!" << std::endl;
            return true;
        }

        return false;
}

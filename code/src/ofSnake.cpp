#include "ofSnake.h"
#include "ofConfig.h"

// Constructor
ofSnake::ofSnake()
{
    body.push_back(ofVec2f(100, 100)); // Start with one segment at position (100, 100)
    xSpeed = 0;                        // Initial speed is zero
    ySpeed = 0;
    color.set(255);      // Color white
    loadSegmentImages(); // Load the segment images
    currentFrame = 0;
    frameDuration = 0.1f; // Change frame every 0.1 seconds
    lastFrameTime = ofGetElapsedTimef();
}

// Destructor
ofSnake::~ofSnake()
{
    std::cout << "help, I will die" << std::endl;
}

// Load the segment images
void ofSnake::loadSegmentImages()
{
    int numFrames = 6; // Adjust this to the number of frames you have
    for (int i = 0; i < numFrames; ++i)
    {
        ofImage img;
        std::string fileName = "ant_" + std::to_string(i) + ".png";
        if (img.load(fileName))
        {
            segmentImages.push_back(img);
        }
        else
        {
            ofLogError() << "Failed to load image: " << fileName;
        }
    }
}

// Update the snake's position
void ofSnake::updateSnake()
{
    // Move all segments
    for (int i = body.size() - 1; i > 0; i--)
    {
        body[i] = body[i - 1]; // Each segment moves to the position of the previous one
    }
    // Update the head position based on current direction
    body[0].x += xSpeed * gridSize;
    body[0].y += ySpeed * gridSize;

    // Screen wrapping logic
    if (body[0].x >= ofGetWidth())
    {
        body[0].x = 0;
    }
    else if (body[0].x < 0)
    {
        body[0].x = ofGetWidth() - gridSize;
    }

    if (body[0].y >= ofGetHeight())
    {
        body[0].y = 0;
    }
    else if (body[0].y < 0)
    {
        body[0].y = ofGetHeight() - gridSize;
    }
}

// Draw the snake using the loaded image sequence
void ofSnake::drawSnake()
{
    ofSetColor(255); // Ensure the color is white to draw the image without tint

    // Update current frame based on elapsed time
    float currentTime = ofGetElapsedTimef();
    if (currentTime - lastFrameTime >= frameDuration)
    {
        currentFrame = (currentFrame + 1) % segmentImages.size();
        lastFrameTime = currentTime;
    }

    for (size_t i = 0; i < body.size(); ++i)
    {
        ofVec2f segment = body[i];

        // Determine the angle based on direction
        float angle = 0;
        if (i == 0)
        { // Head of the snake
            if (xSpeed == 1)
            {
                angle = 90; // Facing right
            }
            else if (xSpeed == -1)
            {
                angle = -90; // Facing left
            }
            else if (ySpeed == 1)
            {
                angle = 180; // Facing down
            }
            else if (ySpeed == -1)
            {
                angle = 0; // Facing up
            }
        }
        else
        { // Body segments follow the head, so no rotation needed
            ofVec2f prevSegment = body[i - 1];
            if (segment.x < prevSegment.x)
            {
                angle = 90;
            }
            else if (segment.x > prevSegment.x)
            {
                angle = -90;
            }
            else if (segment.y < prevSegment.y)
            {
                angle = 180;
            }
            else if (segment.y > prevSegment.y)
            {
                angle = 0;
            }
        }

        ofPushMatrix();
        ofTranslate(segment.x + gridSize / 2, segment.y + gridSize / 2); // Move to the center of the segment
        ofRotateDeg(angle);                                              // Rotate around the center of the segment
        ofTranslate(-gridSize / 2, -gridSize / 2);                       // Move back to the top-left corner
        segmentImages[currentFrame].draw(0, 0, gridSize, gridSize);      // Draw the current frame
        ofPopMatrix();
    }
}

// Set the snake's direction
void ofSnake::setDir(int x, int y)
{
    xSpeed = x;
    ySpeed = y;
}

// Grow the snake by adding a new segment
void ofSnake::grow()
{
    if (!body.empty())
    {
        ofVec2f newSegment = body.back();
        newSegment.x -= xSpeed * gridSize;
        newSegment.y -= ySpeed * gridSize;
        body.push_back(newSegment);
        std::cout << "New segment added. Total segments: " << body.size() << std::endl;
    }
}

// Check if the snake eats the food
bool ofSnake::eat(ofVec2f foodPos)
{
    if (body.empty())
        return false;

    if (body[0].distance(foodPos) < gridSize)
    {
        std::cout << "eat!" << std::endl;
        return true;
    }

    return false;
}

// Check for self collision

bool ofSnake::checkSelfCollision()
{
    if (body.size() < 5)
        return false; // No collision if the snake has less than 5 segments (arbitrary choice to avoid false positives during sharp turns)

    ofVec2f head = body[0];
    for (size_t i = 4; i < body.size(); ++i)
    { // Start checking from the 5th segment onward
        if (head == body[i])
        {
            std::cout << "collided!" << std::endl;
            return true; // Collision detected
        }
    }
    return false;
}

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#define USE_INTERACTION_FUNCTIONS
#include "lpcgraphics.h"
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int initx=0, int inity=0) : x(initx), y(inity) {}
};

const int BALL_RADIUS = 8;
const int BALL_DIAMETER = BALL_RADIUS * 2;
const int PADDLE_WIDTH = 100;
const int PADDLE_HEIGHT = 10;
const int BRICK_WIDTH = 44;
const int BRICK_HEIGHT = 20;
const Color PADDLE_COLOR("white");
const Color BALL_COLOR("lightgray");
Color brickColors[4] = { Color("pink"), Color("lightgreen"), Color("lightblue"), Color("yellow") };
vector<Point> brickPoints(40);

bool hasGameStarted = false;
bool isGameOver = false;
int ballX;
int ballY;
int paddleX;
int paddleY;
int ballSpeedX;
int ballSpeedY;

__INTERACTION_FUNCTIONS__

void setup()
{
    // Initial ball position
    ballX = width / 2;
    ballY = height - PADDLE_HEIGHT - BALL_RADIUS;
    
    paddleX = width / 2 - PADDLE_WIDTH / 2;
    paddleY = height - PADDLE_HEIGHT;
    
    for (int i = 0; i < 40; i++)
    {
        int r = i / 10;
        int c = i % 10;
        brickPoints[i].x = c*(BRICK_WIDTH+4) + 2;
        brickPoints[i].y = r*(BRICK_HEIGHT+4) + 2;
    }
}

void draw()
{
    if (!isGameOver)
    {
        background(60);
        
        // Draw the ball.
        noStroke();
        fillColor(BALL_COLOR);
        ellipse(ballX, ballY, BALL_DIAMETER, BALL_DIAMETER);
        
        // Draw the paddle.
        fillColor(PADDLE_COLOR);
        rect(paddleX, paddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
        
        // TODO: check for wall collisions
        
        // TODO: draw the bricks.
        fillColor(PADDLE_COLOR);
        for (int i = 0; i < brickPoints.size(); i++) {
            fillColor(brickColors[brickPoints[i].y/BRICK_HEIGHT]);
            rect(brickPoints[i].x, brickPoints[i].y, BRICK_WIDTH, BRICK_HEIGHT);
        }
        
        // TODO: check for brick collisions
        if (didHitSide())
            ballSpeedX = -ballSpeedX;
        
        if (checkForCollisions() || didHitTop())
            ballSpeedY = -ballSpeedY;
            
        
        // TODO: check for paddle collision.
        
        // Move the ball.
        ballX += ballSpeedX;
        ballY += ballSpeedY;
        
        // paddle movement
        paddleX = mouseX - PADDLE_WIDTH / 2;
    
        if (!hasGameStarted)
        {
            ballX = mouseX;
        }
    }
}


void mouseReleased()
{
    if (!hasGameStarted)
    {
        ballSpeedX = 15;
        ballSpeedY = -9;
        hasGameStarted = true;
    }
}

bool didHitSide()
{
    return (ballX < BALL_RADIUS || ballX > (width - BALL_RADIUS));
}


bool didHitTop()
{
    // TODO
    return false;
}

/**
 * Return true with the ball passed through the bottom.
 */
bool isOutOfBounds()
{
    // TODO
    return false;
}

/**
 * Detects whether the ball is colliding with a brick.
 * Use a loop to check every brick for collisions.
 * If a brick has been hit, remove it and return true.
 * If not bricks are being hit, return false.
 */
bool checkForCollisions()
{
    // TODO
    for (int i = 0; i < 40; i++)
    {
        if (isBallCollidingWithRect(brickPoints[i].x, brickPoints[i].y, BRICK_WIDTH, BRICK_HEIGHT))
        {
            brickPoints.erase(brickPoints.begin() + i);
            return true;
        }
    }
    return false;
}

/**
 * Given the x, y, w, and, h of a rectangle, determine if the ball
 * is currently colliding with that rect. The x and y of the ball
 * are determined by the ballX and ballY instance variables.
 */
bool isBallCollidingWithRect(int x, int y, int w, int h)
{
    int closestX = max(x, min(ballX, x + w));
    int closestY = max(y, min(ballY, y + h));
    
    int distX = ballX - closestX;
    int distY = ballY - closestY;
    
    int distXSquared = distX * distX;
    int distYSquared = distY * distY;
    int radiusSquared = BALL_RADIUS * BALL_RADIUS;
    
    if ((distXSquared + distYSquared) < radiusSquared)
    {
        return true;
    }

    return false;
}

/**
 * Loops over every brick. If an unbroken brick is found, true false.
 * If every brick has been broken, return true.
 */
bool areAllBricksBroken()
{
    return false;
}

/**
 * Ends the game.
 * If param `didWin` is true, congratulate the use, else boo them.
 * Prompt the user to click to restart the game.
 * Ensure that the text is centered on the screen.
 * Remember to set `isGameOver` to true.
 */
void gameOver(bool didWin)
{
    
}

/**
 * Restarts the game by reseting all of the instance variables.
 */
void restartGame()
{
    
}

__INTERACTION_FUNCTIONS_END__

int main()
{
    startGraphics(480, 480, "Breakout!");
    waitForClose();
}

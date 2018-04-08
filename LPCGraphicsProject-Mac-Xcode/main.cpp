#if 0

#include <iostream>
#include <cstdlib>
#include <cmath>
#define USE_INTERACTION_FUNCTIONS
#include "lpcgraphics.h"
using namespace std;

const double SPEED = 10;
const double RADIUS = 5;
const Color BACKGROUND_COLOR("DarkGray");
const Color BALL_COLOR("LightBlue");
const Color BALL_EDGE("White");

struct Ball {
    double x;
    double y;
    double vx;
    double vy;
    Ball(double xx, double yy, double vxx, double vyy) : x(xx), y(yy), vx(vxx), vy(vyy) {}
};

vector<Ball> balls;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

__INTERACTION_FUNCTIONS__

void setup()
{
    fillColor(BALL_COLOR);
    strokeColor(BALL_EDGE);
    frameRate(30);
}

void keyPressed()
{
    switch (keyCode) {
        case keySPACE:
            balls.clear();
            break;
        case keyESC:
            stopGraphics();
            break;
    }
}

void draw()
{
    background(BACKGROUND_COLOR);
    for (int i = 0; i < balls.size(); i++)
    {
        if (balls[i].x < RADIUS || balls[i].x > width-RADIUS)
            balls[i].vx = -balls[i].vx;
        if (balls[i].y < RADIUS || balls[i].y > height-RADIUS)
            balls[i].vy = -balls[i].vy;
        
        balls[i].x += balls[i].vx;
        balls[i].y += balls[i].vy;

        ellipse(balls[i].x, balls[i].y, RADIUS*2, RADIUS*2);
    }
}

void mousePressed() {
    double angle = fRand(0, 2*M_PI);
    Ball b(mouseX, mouseY, SPEED*cos(angle), SPEED*sin(angle));
    balls.push_back(b);
}

__INTERACTION_FUNCTIONS_END__

int main()
{
    cout << "Hello\n";
    startGraphics(600, 400, "My Game");
    waitForClose();
    cout << "Goodbye\n";
}

#endif

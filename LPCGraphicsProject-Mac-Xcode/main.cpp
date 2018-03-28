#include <iostream>
#include <cstdio>
#include "lpcgraphics.h"
using namespace std;

int xpos = 0;


void setup() {
    Image rock = loadImage("rock.bmp");
    background(0);
    //fillColor(0, 255, 0);
    fillColor("blue");
    strokeColor("red");
    ellipse(250, 150, 50, 70);
    line(0, 0, 500, 150);
    rect(10, 50, 100, 50);
    fillColor("magenta");
    quad(300, 200, 350, 150, 400, 260, 300, 250);
    image(rock, 80, 80);
}

void draw() {
    background(0);
    ellipse(xpos, 150, 50, 50);
    xpos = (xpos + 5) % width;
    
}


int main()
{
    initGraphics(500, 300, "This is your window");
    addSetupFunction(setup);
    addDrawFunction(draw);
    runGraphics();

    cout << "Have a nice day!" << endl;
}

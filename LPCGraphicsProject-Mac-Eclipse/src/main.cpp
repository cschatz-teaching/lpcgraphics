#include <iostream>
#define USE_INTERACTION_FUNCTIONS
#include "lpcgraphics.h"
using namespace std;

__INTERACTION_FUNCTIONS__

void setup()
{
    background(50);
    fillColor("LightBlue");
    text("HELLO WORLD", 200, 100, 32);
    fillColor("Green");
    strokeColor("White");
}

void keyPressed()
{
	if (keyCode == keySPACE)
	{
		stopGraphics();
	}
}

void draw()
{
    if (mouseDown())
    {
        ellipse(mouseX(), mouseY(), 10, 10);
    }
}


__INTERACTION_FUNCTIONS_END__

int main()
{
    cout << "Starting graphics.\n";
    startGraphics(600, 400, "Hello Graphics World");
    waitForClose();
    cout << "Window closed.\n";
}


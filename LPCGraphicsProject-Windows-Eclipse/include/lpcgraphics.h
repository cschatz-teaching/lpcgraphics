#ifndef LPCGRAPHICS_H
#define LPCGRAPHICS_H

#include <string>
#include <vector>
#include <iostream>
#include "internal.h"
#include "color.h"
using namespace std;

// global graphics variables
extern int width;
extern int height;
extern unsigned int keyCode;
void frameRate(double rate);
void stopGraphics();
void waitForClose();

int mouseX();
int mouseY();
bool mouseDown();

void background(Color c);
void background(int r, int g, int b);
void strokeColor(Color c);
void strokeColor(int r, int g, int b);
void fillColor(Color c);
void fillColor(int r, int g, int b);
void noStroke();
void noFill();

void ellipse(int centerX, int centerY, int width, int height);
void line(int x1, int y1, int x2, int y2);
void point(int x, int y);
void rect(int x, int y, int w, int h);
void quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
void text(string s, int x, int y, int fontSize);

Image loadImage(string fileName);
void image(Image img, int x, int y);
void image(Image img, int x, int y, int width, int height);
void image(Image img, int x, int y, double angle);

#endif /* LPCGRAPHICS_H */

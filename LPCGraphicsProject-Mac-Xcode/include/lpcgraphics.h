#ifndef LPCGRAPHICS_H
#define LPCGRAPHICS_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef void* Image;

// global graphics variables
extern int width;
extern int height;
extern int mouseX;
extern int mouseY;
extern bool mousePressed;

void initGraphics(int windowWidth, int windowHeight, string title);
void addSetupFunction(void (*fn)());
void addDrawFunction(void (*fn)());
void runGraphics();
void frameRate(double rate);

void background(unsigned int red, unsigned int green, unsigned int blue);
void background(unsigned int gray);
void background(string str);

void strokeColor(unsigned int red, unsigned int green, unsigned int blue);
void strokeColor(unsigned int gray);
void strokeColor(string str);

void fillColor(unsigned int r, unsigned int g, unsigned int b);
void fillColor(unsigned int gray);
void fillColor(string str);

void noStroke();
void noFill();

void ellipse(int centerX, int centerY, int width, int height);
void line(int x1, int y1, int x2, int y2);
void point(int x, int y);
void rect(int x, int y, int w, int h);
void quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void triangle(int x1, int y1, int x2, int y2, int x3, int y3);

Image loadImage(string fileName);
void image(Image img, int x, int y);
void image(Image img, int x, int y, int width, int height);
void image(Image img, int x, int y, double angle);

//void DrawLine(int x1, int y1, int x2, int y2, Color color);
//void DrawCircle(int x, int y, int radius, Color color, bool filled = false);
//void DrawEllipse(int x, int y, int xradius, int yradius, Color color, bool filled = false);
//void DrawRectangle(int x, int y, int width, int height, Color color, bool filled = false);
//void DrawString(string str, int x, int y, Color color, int fontsize = 13);
//void DrawImage(string imageFileName, int x, int y, int width = 0, int height = 0);

int MouseX();
int MouseY();
bool MouseIsDown();

bool KeyPressed(string key);
string WhatKey();
    

#endif

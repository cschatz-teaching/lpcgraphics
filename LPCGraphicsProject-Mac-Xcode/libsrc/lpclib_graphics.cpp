/*********************************************************************

 === WARNING! ===
 
 The code in this file only contains INTERNAL IMPLEMENTATION code 
 for the LPCGraphics library. You SHOULD NOT edit it, and you do NOT
 need to read or understand it in order to use the library.

**********************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include "CImg.h"
#include "lpcgraphics.h"
#include "color.h"
#include "utility.h"
using namespace cimg_library;

extern string _color_table[296];
extern map<string, string> _color_map;
map<string, CImg<unsigned char> *> _imagemap;
CImgDisplay * _gdisplay;
CImg<unsigned char> * _gpixels;
bool _graphics_ready = false;
vector<void (*)()> _setup_functions;
vector<void (*)()> _draw_functions;
double _frameRate = 30;
Color _fillColor;
Color _strokeColor;
bool _useFill = true;
bool _useStroke = true;
thread * _eventThread = nullptr;
void _eventLoop();
int _eventCount = 0;

int width;
int height;
int mouseX;
int mouseY;
bool mousePressed = false;


static void _refresh();
static void _setBackground(const Color& backgroundColor);

void background(unsigned int r, unsigned int g, unsigned int b)
{
    _setBackground(Color(r, g, b));
}

void background(unsigned int gray)
{
    _setBackground(Color(gray));
}

void background(string str)
{
    _setBackground(Color(str));
}

void fillColor(unsigned int r, unsigned int g, unsigned int b)
{
    _fillColor = Color(r, g, b);
    _useFill = true;
}

void fillColor(unsigned int gray)
{
    _fillColor = Color(gray);
    _useFill = true;
}

void fillColor(string str)
{
    _fillColor = Color(str);
    _useFill = true;
}

void strokeColor(unsigned int r, unsigned int g, unsigned int b)
{
    _strokeColor = Color(r, g, b);
    _useStroke = true;
}

void strokeColor(unsigned int gray)
{
    _strokeColor = Color(gray);
    _useStroke = true;
}

void strokeColor(string str)
{
    _strokeColor = Color(str);
    _useStroke = true;
}

void initGraphics(int windowWidth, int windowHeight, string title)
{
    if (_graphics_ready)
        Error("initGraphics() was called a second time before runGraphics()");
    
    width = windowWidth;
    height = windowHeight;
    
    _gpixels = new CImg<unsigned char>(width, height, 1, 3);
    _gdisplay = new CImgDisplay(*(_gpixels), title.c_str());
    _gpixels->display(*(_gdisplay));
    
    if (_gdisplay->window_width() != width)
        Error("Requested width " + IntToString(width) + " does not fit the screen.");
    if (_gdisplay->height() != height)
        Error("Requested height " + IntToString(height) + " does not fit the screen.");
    
    _eventThread = new thread(_eventLoop);
    
    _graphics_ready = true;
}

void frameRate(double rate)
{
    _frameRate = rate;
}

void noFill()
{
    _useFill = false;
}

void noStroke()
{
    _useStroke = false;
}

void addSetupFunction(void (*fn)())
{
    _setup_functions.push_back(fn);
}

void addDrawFunction(void (*fn)())
{
    _draw_functions.push_back(fn);
}

void runGraphics()
{
    for (unsigned int i = 0; i < _setup_functions.size(); i++)
    {
        (_setup_functions[i])();
    }
    _refresh();
    
    while (true)
    {
        for (unsigned int i = 0; i < _draw_functions.size(); i++)
            _draw_functions[i]();
        _refresh();
        if (_gdisplay->is_closed())
            break;
        _gdisplay->wait(1000.0 / _frameRate);
        mouseX = _gdisplay->mouse_x();
        mouseY = _gdisplay->mouse_y();
    }
    
    // Done
    delete _gpixels;
    delete _gdisplay;
    delete _eventThread;
    _graphics_ready = false;
}

void ellipse(int centerX, int centerY, int width, int height)
{
    if (_useFill)
        _gpixels->draw_ellipse(centerX, centerY, width / 2.0, height / 2.0, 0, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_ellipse(centerX, centerY, width / 2.0, height / 2.0, 0, _strokeColor._components, 1, ~0);
}

void line(int x1, int y1, int x2, int y2)
{
    if (_useStroke)
        _gpixels->draw_line(x1, y1, x2, y2, _strokeColor._components);
}

void point(int x, int y)
{
    if (_useStroke)
        _gpixels->draw_point(x, y, _strokeColor._components);
}

void rect(int x, int y, int w, int h)
{
    if (_useFill)
        _gpixels->draw_rectangle(x, y, x+w, y+h, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_rectangle(x, y, x+w, y+h, _strokeColor._components, 1, ~0);
}

void quad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    CImg<unsigned int> points(4, 2);
    points(0, 0) = x1;
    points(0, 1) = y1;
    points(1, 0) = x2;
    points(1, 1) = y2;
    points(2, 0) = x3;
    points(2, 1) = y3;
    points(3, 0) = x4;
    points(3, 1) = y4;
    
    _gpixels->draw_polygon(points, _fillColor._components);
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    CImg<unsigned int> points(3, 2);
    points(0, 0) = x1;
    points(0, 1) = y1;
    points(1, 0) = x2;
    points(1, 1) = y2;
    points(2, 0) = x3;
    points(2, 1) = y3;
    
    _gpixels->draw_polygon(points, _fillColor._components);
}


Image loadImage(string fileName)
{
    CImg<unsigned char>* img  = new CImg<unsigned char>((string("images/") + fileName).c_str());
    if (! img)
        Error(string("Could not load image '") + fileName + "'");
    return img;
}

void image(Image img, int x, int y)
{
    CImg<unsigned char>* ptr = (CImg<unsigned char>*)img;
    _gpixels->draw_image(x, y, *ptr);
}

void image(Image img, int x, int y, int width, int height)
{
     CImg<unsigned char>* ptr = (CImg<unsigned char>*)img;
    _gpixels->draw_image(x, y, ptr->get_resize(width, height));
}

void image(Image img, int x, int y, double angle)
{
     CImg<unsigned char>* ptr = (CImg<unsigned char>*)img;
    _gpixels->draw_image(x, y, ptr->get_rotate(angle));
}



void _eventLoop() {
    while (true)
    {
        if (_gdisplay->is_event()) {
            if (_gdisplay->button() & 0x1 && !mousePressed) {
                cout << "Mouse DOWN\n";
                mousePressed = true;
            } else if (!(_gdisplay->button() & 0x1) && mousePressed) {
                cout << "Mouse UP\n";
                mousePressed = false;
            }
        }
    }
}


void _refresh()
{
    _gpixels->display(*(_gdisplay));
}

void _setBackground(const Color& backgroundColor)
{
    _gpixels->draw_rectangle(0, 0, _gpixels->width(), _gpixels->height(), backgroundColor._components);
}

bool KeyPressed(string key)
{
    static int last = 0;
    
    int what = 0;
    if (key.length() == 1)
        what = key[0];
    else if (key == "up")
        what = cimg_library::cimg::keyARROWUP;
    else if (key == "down")
        what = cimg_library::cimg::keyARROWDOWN;
    else if (key == "left")
        what = cimg_library::cimg::keyARROWLEFT;
    else if (key == "right")
        what = cimg_library::cimg::keyARROWRIGHT;
    
    if (_gdisplay->key() == what)
    {
        last = what;
        return true;
    }
    else if (_gdisplay->released_key() == what)
    {
        _gdisplay->unrelease_key();
        if (last == what)
        {
            last = 0;
            return false;
        }
        else
            return true;
    }
    return false;
}

string WhatKey()
{
    char c =_gdisplay->key();
    string s = "";
    s += c;
    return s;
}

//
//    if (width == 0 && height == 0)
//        _gpixels->draw_image(x, y, *img);
//    else
//        _gpixels->draw_image(x, y, img->get_resize(width, height));

//void DrawString(string str, int x, int y, Color color, int fontsize)
//{
//    _gpixels->draw_text (x, y, str.c_str(), color._components, NULL, 1, fontsize);
//}
//


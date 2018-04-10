/*********************************************************************
 
 === WARNING! ===
 
 The code in this file only contains INTERNAL IMPLEMENTATION code
 for the LPCGraphics library. You SHOULD NOT edit it, and you do NOT
 need to read or understand it in order to use the library.
 
 **********************************************************************/

#include <iostream>
#include <thread>
#include "CImg.h"
#include "lpcgraphics.h"
#include "color.h"
#include "utility.h"
using namespace cimg_library;

int width;
int height;
unsigned int keyCode = 0;

extern double _frameRate;
extern cimg_library::CImgDisplay * _gdisplay;
extern cimg_library::CImg<unsigned char> * _gpixels;
extern Color _fillColor;
extern Color _strokeColor;
extern bool _useFill;
extern bool _useStroke;
extern thread * _eventThread;
extern bool _mouseDown;
void _refresh();
_hooks * _driver;

int mouseX()
{
    return _gdisplay->mouse_x();
}

int mouseY()
{
    return _gdisplay->mouse_y();
}

bool mouseDown()
{
    return _gdisplay->button() & 0x1;
}


void background(Color c)
{
    _gpixels->draw_rectangle(0, 0, _gpixels->width(), _gpixels->height(), c._components);
    if (!_driver)
        _refresh();
    
}

void background(int r, int g, int b)
{
    background(Color(r, g, b));
}

void fillColor(Color c)
{
    _fillColor = c;
    _useFill = true;
}

void fillColor(int r, int g, int b)
{
    fillColor(Color(r, g, b));
}

void strokeColor(Color c)
{
    _strokeColor = c;
    _useStroke = true;
}

void strokeColor(int r, int g, int b)
{
    strokeColor(Color(r, g, b));
}

void noFill()
{
    _useFill = false;
}

void noStroke()
{
    _useStroke = false;
}


void frameRate(double rate)
{
    _frameRate = rate;
}

void ellipse(int centerX, int centerY, int width, int height)
{
    if (_useFill)
        _gpixels->draw_ellipse(centerX, centerY, width / 2.0, height / 2.0, 0, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_ellipse(centerX, centerY, width / 2.0, height / 2.0, 0, _strokeColor._components, 1, ~0);
    
    if (!_driver)
        _refresh();
}

void line(int x1, int y1, int x2, int y2)
{
    if (_useStroke)
        _gpixels->draw_line(x1, y1, x2, y2, _strokeColor._components);
    if (!_driver)
        _refresh();
}

void point(int x, int y)
{
    if (_useStroke)
        _gpixels->draw_point(x, y, _strokeColor._components);
    if (!_driver)
        _refresh();
}

void rect(int x, int y, int w, int h)
{
    if (_useFill)
        _gpixels->draw_rectangle(x, y, x+w, y+h, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_rectangle(x, y, x+w, y+h, _strokeColor._components, 1, ~0);
    if (!_driver)
        _refresh();
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
    
    if (_useFill)
        _gpixels->draw_polygon(points, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_polygon(points, _strokeColor._components, 1, ~0);
    if (!_driver)
        _refresh();
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
    
    if (_useFill)
        _gpixels->draw_polygon(points, _fillColor._components);
    if (_useStroke)
        _gpixels->draw_polygon(points, _strokeColor._components, 1, ~0);
    if (!_driver)
        _refresh();
}

void text(string s, int x, int y, int fontSize)
{
    if (_useFill)
        _gpixels->draw_text(x, y, s.c_str(), _fillColor._components, NULL, 1, fontSize);
    if (!_driver)
        _refresh();
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
    if (!_driver)
        _refresh();
}

void image(Image img, int x, int y, int width, int height)
{
    CImg<unsigned char>* ptr = (CImg<unsigned char>*)img;
    _gpixels->draw_image(x, y, ptr->get_resize(width, height));
    if (!_driver)
        _refresh();
}

void image(Image img, int x, int y, double angle)
{
    CImg<unsigned char>* ptr = (CImg<unsigned char>*)img;
    _gpixels->draw_image(x, y, ptr->get_rotate(angle));
    if (!_driver)
        _refresh();
}


void waitForClose()
{
    if (_driver && _eventThread)
        _eventThread->join();
    else if (!_driver)
    {
        while (!(_gdisplay->is_closed()))
            ;
    }
}

void stopGraphics()
{
    _gdisplay->close();
}



/*********************************************************************

 === WARNING! ===

 The code in this file only contains INTERNAL IMPLEMENTATION code
 for the LPCGraphics library. You SHOULD NOT edit it, and you do NOT
 need to read or understand it in order to use the library.

 **********************************************************************/

#include <set>
#include <process.h>
#include "CImg.h"
#include "lpcgraphics.h"
#include "color.h"
#include "utility.h"

set<unsigned int> _keySet;
cimg_library::CImgDisplay * _gdisplay;
cimg_library::CImg<unsigned char> * _gpixels;
bool _graphics_ready = false;
double _frameRate = 30;
Color _fillColor;
Color _strokeColor;
bool _useFill = true;
bool _useStroke = true;
HANDLE _drawThread = NULL;
HANDLE _eventThread = NULL;
unsigned __stdcall _drawLoop(void *unused);
unsigned __stdcall _eventLoop(void *unused);
void _refresh();
bool _mouseDown = false;

void _init(int w, int h, string t)
{
    if (_graphics_ready)
        Error("startGraphics() was called twice");

    width = w;
    height = h;

    _gpixels = new cimg_library::CImg<unsigned char>(width, height, 1, 3);
    _gdisplay = new cimg_library::CImgDisplay(*(_gpixels), t.c_str());
    _gpixels->display(*(_gdisplay));

    if (_gdisplay->window_width() != width)
        Error("Requested width " + IntToString(width) + " does not fit the screen.");
    if (_gdisplay->height() != height)
        Error("Requested height " + IntToString(height) + " does not fit the screen.");
    
    _graphics_ready = true;
    
    if (_driver) {
        _driver->setup();
        _drawThread = (HANDLE) _beginthreadex(NULL, 0, _drawLoop, NULL, 0, NULL);
        _eventThread =  (HANDLE) _beginthreadex(NULL, 0, _eventLoop, NULL, 0, NULL);

    }
}

void _refresh()
{
    _gpixels->display(*(_gdisplay));
}


unsigned __stdcall _eventLoop(void *unused) {
    while (!(_gdisplay->is_closed()))
    {
        if (_gdisplay->is_event()) {
            if ((_gdisplay->button() & 0x1) && !_mouseDown) {
                _mouseDown = true;
                _driver->mousePressed();
                _refresh();
            }
            if (!(_gdisplay->button() & 0x1) && _mouseDown) {
                _mouseDown = false;
                _driver->mouseReleased();
                _refresh();
            }
            unsigned int k = _gdisplay->key();
            if (k != 0 && _keySet.find(k) == _keySet.end()) {
                _keySet.insert(k);
                keyCode = k;
                _driver->keyPressed();
                _refresh();
            } else {
                unsigned int kr = _gdisplay->released_key();
                if (kr != 0 && _keySet.find(kr) != _keySet.end()) {
                    _keySet.erase(kr);
                    _driver->keyReleased();
                    _refresh();
                }
            }
        }
    }
    return 0;
}

unsigned __stdcall _drawLoop(void *unused) {
    while (true)
    {
        _driver->draw();
        _refresh();
        if (_gdisplay->is_closed())
            break;
        cimg_library::cimg::wait(1000.0 / _frameRate);
    }

    // Done
    delete _gdisplay;
    delete _gpixels;
    _graphics_ready = false;
    return 0;
}

void _waitForClose()
{
    if (_driver && _drawThread )
    {
    	WaitForSingleObject(_drawThread, INFINITE);
    }
    else if (!_driver)
    {
        while (!(_gdisplay->is_closed()))
            ;
    }

}

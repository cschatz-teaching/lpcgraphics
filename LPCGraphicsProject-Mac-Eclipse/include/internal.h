#ifndef internal_h
#define internal_h

#include <string>
using namespace std;

typedef void* Image;

class _hooks {
public:
    virtual void setup() {};
    virtual void draw() {};
    virtual void mousePressed() {};
    virtual void mouseReleased() {};
    virtual void keyPressed() {};
    virtual void keyReleased() {};
};

extern _hooks * _driver;
void _init(int w, int h, string t);

#ifdef USE_INTERACTION_FUNCTIONS
#define __INTERACTION_FUNCTIONS__ class _clienthooks : public _hooks {
#define __INTERACTION_FUNCTIONS_END__ };
#define startGraphics(w, h, t) { _driver = new _clienthooks; _init(w, h, t); }
#else
#define __INTERACTION_FUNCTIONS__
#define __INTERACTION_FUNCTIONS_END__
#define startGraphics(w, h, t) { _driver = nullptr; _init(w, h, t); }
#endif

#endif /* internal_h */

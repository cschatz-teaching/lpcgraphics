#ifndef color_h
#define color_h
#include <string>
using namespace std;

struct Color
{
    Color(unsigned int red, unsigned int green, unsigned int blue);
    Color(unsigned int gray);
    Color(string colorName);
    Color();
    
    unsigned int _components[3];
    void checkinit();
};

#endif /* color_h */

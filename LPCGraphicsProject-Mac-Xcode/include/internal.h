#ifndef internal_h
#define internal_h

#include <string>
#include "CImg.h"
using namespace std;

#define KEYS cimg_library::cimg

typedef void* Image;

const unsigned int keyESC = cimg_library::cimg::keyESC;
const unsigned int keyF1 = cimg_library::cimg::keyF1;
const unsigned int keyF2 = cimg_library::cimg::keyF2;
const unsigned int keyF3 = cimg_library::cimg::keyF3;
const unsigned int keyF4 = cimg_library::cimg::keyF4;
const unsigned int keyF5 = cimg_library::cimg::keyF5;
const unsigned int keyF6 = cimg_library::cimg::keyF6;
const unsigned int keyF7 = cimg_library::cimg::keyF7;
const unsigned int keyF8 = cimg_library::cimg::keyF8;
const unsigned int keyF9 = cimg_library::cimg::keyF9;
const unsigned int keyF10 = cimg_library::cimg::keyF10;
const unsigned int keyF11 = cimg_library::cimg::keyF11;
const unsigned int keyF12 = cimg_library::cimg::keyF12;
const unsigned int keyPAUSE = cimg_library::cimg::keyPAUSE;
const unsigned int key1 = cimg_library::cimg::key1;
const unsigned int key2 = cimg_library::cimg::key2;
const unsigned int key3 = cimg_library::cimg::key3;
const unsigned int key4 = cimg_library::cimg::key4;
const unsigned int key5 = cimg_library::cimg::key5;
const unsigned int key6 = cimg_library::cimg::key6;
const unsigned int key7 = cimg_library::cimg::key7;
const unsigned int key8 = cimg_library::cimg::key8;
const unsigned int key9 = cimg_library::cimg::key9;
const unsigned int key0 = cimg_library::cimg::key0;
const unsigned int keyBACKSPACE = cimg_library::cimg::keyBACKSPACE;
const unsigned int keyINSERT = cimg_library::cimg::keyINSERT;
const unsigned int keyHOME = cimg_library::cimg::keyHOME;
const unsigned int keyPAGEUP = cimg_library::cimg::keyPAGEUP;
const unsigned int keyTAB = cimg_library::cimg::keyTAB;
const unsigned int keyQ = cimg_library::cimg::keyQ;
const unsigned int keyW = cimg_library::cimg::keyW;
const unsigned int keyE = cimg_library::cimg::keyE;
const unsigned int keyR = cimg_library::cimg::keyR;
const unsigned int keyT = cimg_library::cimg::keyT;
const unsigned int keyY = cimg_library::cimg::keyY;
const unsigned int keyU = cimg_library::cimg::keyU;
const unsigned int keyI = cimg_library::cimg::keyI;
const unsigned int keyO = cimg_library::cimg::keyO;
const unsigned int keyP = cimg_library::cimg::keyP;
const unsigned int keyDELETE = cimg_library::cimg::keyDELETE;
const unsigned int keyEND = cimg_library::cimg::keyEND;
const unsigned int keyPAGEDOWN = cimg_library::cimg::keyPAGEDOWN;
const unsigned int keyCAPSLOCK = cimg_library::cimg::keyCAPSLOCK;
const unsigned int keyA = cimg_library::cimg::keyA;
const unsigned int keyS = cimg_library::cimg::keyS;
const unsigned int keyD = cimg_library::cimg::keyD;
const unsigned int keyF = cimg_library::cimg::keyF;
const unsigned int keyG = cimg_library::cimg::keyG;
const unsigned int keyH = cimg_library::cimg::keyH;
const unsigned int keyJ = cimg_library::cimg::keyJ;
const unsigned int keyK = cimg_library::cimg::keyK;
const unsigned int keyL = cimg_library::cimg::keyL;
const unsigned int keyENTER = cimg_library::cimg::keyENTER;
const unsigned int keySHIFTLEFT = cimg_library::cimg::keySHIFTLEFT;
const unsigned int keyZ = cimg_library::cimg::keyZ;
const unsigned int keyX = cimg_library::cimg::keyX;
const unsigned int keyC = cimg_library::cimg::keyC;
const unsigned int keyV = cimg_library::cimg::keyV;
const unsigned int keyB = cimg_library::cimg::keyB;
const unsigned int keyN = cimg_library::cimg::keyN;
const unsigned int keyM = cimg_library::cimg::keyM;
const unsigned int keySHIFTRIGHT = cimg_library::cimg::keySHIFTRIGHT;
const unsigned int keyARROWUP = cimg_library::cimg::keyARROWUP;
const unsigned int keyCTRLLEFT = cimg_library::cimg::keyCTRLLEFT;
const unsigned int keyAPPLEFT = cimg_library::cimg::keyAPPLEFT;
const unsigned int keyALT = cimg_library::cimg::keyALT;
const unsigned int keySPACE = cimg_library::cimg::keySPACE;
const unsigned int keyALTGR = cimg_library::cimg::keyALTGR;
const unsigned int keyAPPRIGHT = cimg_library::cimg::keyAPPRIGHT;
const unsigned int keyMENU = cimg_library::cimg::keyMENU;
const unsigned int keyCTRLRIGHT = cimg_library::cimg::keyCTRLRIGHT;
const unsigned int keyARROWLEFT = cimg_library::cimg::keyARROWLEFT;
const unsigned int keyARROWDOWN = cimg_library::cimg::keyARROWDOWN;
const unsigned int keyARROWRIGHT = cimg_library::cimg::keyARROWRIGHT;
const unsigned int keyPAD0 = cimg_library::cimg::keyPAD0;
const unsigned int keyPAD1 = cimg_library::cimg::keyPAD1;
const unsigned int keyPAD2 = cimg_library::cimg::keyPAD2;
const unsigned int keyPAD3 = cimg_library::cimg::keyPAD3;
const unsigned int keyPAD4 = cimg_library::cimg::keyPAD4;
const unsigned int keyPAD5 = cimg_library::cimg::keyPAD5;
const unsigned int keyPAD6 = cimg_library::cimg::keyPAD6;
const unsigned int keyPAD7 = cimg_library::cimg::keyPAD7;
const unsigned int keyPAD8 = cimg_library::cimg::keyPAD8;
const unsigned int keyPAD9 = cimg_library::cimg::keyPAD9;
const unsigned int keyPADADD = cimg_library::cimg::keyPADADD;
const unsigned int keyPADSUB = cimg_library::cimg::keyPADSUB;
const unsigned int keyPADMUL = cimg_library::cimg::keyPADMUL;
const unsigned int keyPADDIV = cimg_library::cimg::keyPADDIV;

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

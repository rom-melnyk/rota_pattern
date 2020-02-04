#ifndef __CANVAS_H_INCLUDED__
#define __CANVAS_H_INCLUDED__


#include <iostream>
#include <fstream>

using namespace std;
typedef char byte;

struct RGB {
	byte red;
	byte green;
	byte blue;
};


__interface ICanvas {
	void init(const char* fileName, int size); // might be private if you invoke it from constructor
	void drawPixel(const char* fileName, uint16_t x, uint16_t y, RGB color, int size);
	//RGB getPixelAt(uint16_t x, uint16_t y);
	//public ... getAllPixels();
};


#endif

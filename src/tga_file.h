

#ifndef __TGA_FILE_H_INCLUDED__
#define __TGA_FILE_H_INCLUDED__

#include<iostream>
#include<vector>
#include<fstream>
#include "Canvas.h"

using namespace std;
typedef char byte;

class WriteTGA : public Canvas {
protected:
	int height;
	int width;
public:
	WriteTGA(int _height, int _width) : height(_height), width(_width) {}

	byte header[18] = {
	   0,                  //0      id
	   0,                  //1      Color map type
	   2,                  //2      24bit uncompressed RGB
	   0, 0, 0, 0, 0, 	    //3-7    Color map related data
	   0, 0,               //8-9    X origin
	   0, 0,               //10-11  Y origin
	   0, 0,               //12-13  Width
	   0, 0,               //14-15  Height
	   24,                 //16     Means 24bit RGB
	   0                   //17     Image descriptor
	};
	RGB main_color = { (byte)255, (byte)255, (byte)255 };
	ofstream file;
	void writeTargaFile(const char* fileName) {

		file.open(fileName, ios::binary | ios::out);

		if (!file.is_open())
			throw;

		header[12] = width & 0xFF;
		header[13] = (width >> 8) & 0xFF; //take value from the last 8 bits, and ignore all the rest bits       
		header[14] = height & 0xFF;
		header[15] = (height >> 8) & 0xFF;

		file.write((const char*)header, 18);

		
		init(fileName,width);
		putPixelIn(5, 5, main_color);
		test_show();
	}

};


#endif
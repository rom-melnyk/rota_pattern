

#ifndef __TGA_FILE_H_INCLUDED__
#define __TGA_FILE_H_INCLUDED__

#include<iostream>
#include<vector>
#include<fstream>
#include "Canvas.h"

using namespace std;
typedef char byte;



class Canvas : public ICanvas {
	vector<byte> canvas;
	ofstream file;

protected:
	void init(const char* fileName, int size) override {
		
		file.open(fileName, ios::binary | ios::out);
	
		for (int y = 0; y < size; y++)
			for (int x = 0; x < size; x++) {
				canvas.push_back((byte)255);
				canvas.push_back((byte)255);
				canvas.push_back((byte)255);
			}
		for (int y = 0; y < size; y++)
			for (int x = 0; x < size; x++) {
				file.put(canvas.at(x));
				file.put(canvas.at(y));
				file.put(canvas.at(x));
			}
			file.close();
	}

	void drawPixel(const char* fileName, uint16_t _x, uint16_t _y, RGB color, int size) override {


		file.open(fileName, ios::binary | ios::out);
	/*	canvas.at(_x) = color.blue;
		canvas.at(_y) = color.green;
		canvas.at(_x) = color.red;*/
		for (int y = 0; y < size; y++)
			for (int x = 0; x < size; x++) {
				if (x == _x && y == _y) {
					canvas.at(x) = color.blue;
					canvas.at(y) = color.green;
					canvas.at(x) = color.red;
				}
			}

		for (int y = 0; y < size; y++)
			for (int x = 0; x < size; x++) {
					file.put(canvas.at(x));
					file.put(canvas.at(y));
					file.put(canvas.at(x));
				}
				
		file.close();
	}

public:



};

	class WriteTGA : public Canvas {
	protected:
		int height;
		int width;
	public:
		WriteTGA(int _height, int _width) : height(_height), width(_width){}

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
		

		ofstream file;
		 void writeTargaFile(const char* fileName) {

			//RGB data = { (byte)128, (byte)128, (byte)128 };
			RGB color = { (byte)0, (byte)0, (byte)0 };
			file.open(fileName, ios::binary | ios::out);

			if (!file.is_open()) throw;

			header[12] = width & 0xFF;
			header[13] = (width >> 8) & 0xFF; //take value from the last 8 bits, and ignore all the rest bits       
			header[14] = height & 0xFF;
			header[15] = (height >> 8) & 0xFF;

			file.write((const char*)header, 18);

			init(fileName, width);
			drawPixel(fileName, 100, 100, color, width);
			drawPixel(fileName, 20, 100, color, width);  
			drawPixel(fileName, 100, 20, color, width); 
			drawPixel(fileName, 20, 20, color, width);

			/*for (int y = 0; y < height; y++)
				for (int x = 0; x < width; x++) {
					file.put(data.blue);
					file.put(data.green);
					file.put(data.red);

				}
				*/
			file.close();

		}

	};


#endif
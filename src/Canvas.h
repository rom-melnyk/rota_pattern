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
	void init( string fileName ,unsigned int side_length); // might be private if you invoke it from constructor
	void putPixelIn(unsigned int x1, unsigned int y1, RGB color);
	//RGB getPixelAt(uint16_t x, uint16_t y);
	//public ... getAllPixels();
};

class Canvas : public ICanvas {
	
	ofstream file;
	RGB def_color = { (byte)255, (byte)255, (byte)255 };
	unsigned int side_length;

protected:
	vector<vector<RGB>> pixel_data;

	/*Canvas() {
		for (vector<RGB> v1 : pixel_data) {
			for (RGB rgb : v1) {
				rgb.blue = (byte)0;
				rgb.green = (byte)0;
				rgb.red = (byte)0;
			}
		}
	}*/
	void init(string fileName , unsigned int side_length)override
	{
		this->side_length = side_length;
		file.open(fileName, ios::out | ios::binary);

		for (int y = 0; y < side_length; y++) {
			for (int x = 0; x < side_length; x++) {
				//pixel_data.at(y).at(x) = def_color;
				file.put(def_color.blue);
				file.put(def_color.green);
				file.put(def_color.red);
			}
		}
		if(!file.is_open())file.close();
	}

	void putPixelIn(unsigned int x1, unsigned int y1, RGB color)override {
		for (int y = 0; y < side_length; y++) {
			for (int x = 0; x < side_length; x++) {
				if (x == x1 && y == y1) {
					color = pixel_data.at(y).at(x);

					file.put(color.blue);
					file.put(color.green);
					file.put(color.red);

				}
			}
		}
	}
	/*	void init(const char* fileName, int size) override {

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
			/*canvas.at(_x) = color.blue;
			canvas.at(_y) = color.green;
			canvas.at(_x) = color.red;

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


*/
};



#endif

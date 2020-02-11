#ifndef __CANVAS_H_INCLUDED__
#define __CANVAS_H_INCLUDED__


#include <iostream>
#include <vector>

using namespace std;
typedef char byte;

struct RGB 
{
	byte red;
	byte green;
	byte blue;
};

/*__interface ICanvas
{
	//void init(unsigned int side_length); // might be private if you invoke it from constructor
	//void putPixelIn(unsigned int x1, unsigned int y1, RGB color);
	//RGB getPixelAt(uint16_t x, uint16_t y);
	//public ... getAllPixels();
};
*/

class Canvas {

private:
	RGB def_color = { (byte)255, (byte)255, (byte)255 };
	unsigned int side_length;
	vector<vector<RGB>> pixel_data;
public:

	Canvas(unsigned int side_length) {
		this->side_length = side_length;

		for (int x = 0; x < side_length; x++) {
			vector<RGB> line;
			for (int y = 0; y < side_length; y++) {
				line.push_back(def_color);
			}
			pixel_data.push_back(line);
		}
	}
	vector<RGB> get_all_pixels() {
		vector<RGB> result;

		for (unsigned int y = 0; y < side_length; y++) {
			for (unsigned int x = 0; x < side_length; x++) {
				RGB pixel = pixel_data[y][x];
				result.push_back(pixel);
			}
		}
		return result;
	}
	void put_pixel_at(unsigned int x, unsigned int y, RGB color) {
		pixel_data[y][x] = color;
	}
	RGB get_pixel_at(unsigned short x, unsigned short y) {
		return pixel_data[y][x];
	}

};


#endif

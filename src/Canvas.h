#ifndef __CANVAS_H_INCLUDED__
#define __CANVAS_H_INCLUDED__


#include <iostream>
#include <fstream>
#include<math.h>

using namespace std;
typedef char byte;

struct RGB 
{
	byte red;
	byte green;
	byte blue;
};
__interface ICanvas
{
	void init( string fileName ,unsigned int side_length); // might be private if you invoke it from constructor
	void putPixelIn(unsigned int x1, unsigned int y1, RGB color);
	//RGB getPixelAt(uint16_t x, uint16_t y);
	//public ... getAllPixels();
};

class Canvas : public ICanvas
{

	ofstream file;
	string fileName = "";
	RGB def_color = { (byte)200, (byte)200, (byte)200};
	unsigned int side_length;
	vector<vector<RGB>> pixel_data;

public:
	// test method
	void test_show() {   
		for (vector<RGB> data : pixel_data) {
			for (RGB value : data) {
				cout << value.blue << " " << value.green << " " << value.red;
			}
		}
	}
	~Canvas() 
	{
		if (file.is_open())
			file.close();
	}

	void init(string fileName, unsigned int side_length) override
	{
		file.open(fileName, ios::binary);
		if (!file.is_open())
			throw "file is not open";

		this->fileName = fileName;
		this->side_length = side_length;

		// initialization
		for (int x = 0; x < side_length; x++) 
		{
			vector<RGB> v;
			for (int y = 0; y < side_length; y++)
			{
				v.push_back(def_color);
			}
			pixel_data.push_back(v);

		}
		// put pixel data in file
		for (vector<RGB> data : pixel_data) {
			for (RGB value : data) {
				file.put(value.blue);
				file.put(value.green);
				file.put(value.red);
			}
		}
}
	void putPixelIn(unsigned int x1, unsigned int y1, RGB color) override 
	{
			file.open(fileName, ios::binary);

			for (int x = 0; x < side_length; x++)
			{
				for (int y = 0; y < side_length; y++)
				{
					if (x == x1 && y == y1) 
					{
					    RGB data_buff = pixel_data.at(y).at(x);
						pixel_data.at(y).at(x) = color;

						/*file.put(pixel_data.at(y).at(x).blue);
						file.put(pixel_data.at(y).at(x).green);
						file.put(pixel_data.at(y).at(x).red);
						*/
					}
				}
			}
		/*for (vector<RGB> data : pixel_data) {
			for (RGB value : data) {
				file.put(value.blue);
				file.put(value.green);
				file.put(value.red);
			}
		}
		*/
			for (vector<RGB> data : pixel_data) {
				for (RGB value : data) {
					file.put(value.blue);
					file.put(value.green);
					file.put(value.red);
				}
			}
	}


};



#endif



#ifndef __TGA_FILE_H_INCLUDED__
#define __TGA_FILE_H_INCLUDED__

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
typedef char byte;

class WriteTGA {
public: 

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
	struct rgb {
		byte red, green, blue;
	};
	void writeTargaFile(const char* fileName, int height, int width) {

		ofstream file;
		rgb* data = new rgb;

		file.open(fileName, ios::binary|ios::out);

		if (!file.is_open()) throw;

		header[12] = width & 0xFF;
		header[13] = (width >> 8) & 0xFF; //take value from the last 8 bits, and ignore all the rest bits       
		header[14] = height & 0xFF;
		header[15] = (height >> 8) & 0xFF;

		file.write((const char*)header, 18);



		for (int y = 0; y < height; y++) 
			for (int x = 0; x < width; x++) {
				file.put((byte)data[x].blue);
				file.put((byte)data[y].green);
				file.put((byte)data[x].red);
			
			}
		file.close();
		delete[] data;
	 }

};


#endif
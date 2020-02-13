

#ifndef __TGA_FILE_H_INCLUDED__
#define __TGA_FILE_H_INCLUDED__

#include<iostream>
#include<vector>
#include<fstream>
#include "Canvas.h"

using namespace std;
typedef char byte;



class WriteTGA{
private:
	int side_length;

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

public:

	void save(string fileName, vector<RGB> all_data) {
		ofstream file;

		file.open(fileName, ios::binary | ios::out);

		if (!file.is_open()) {
			throw;
		}

		header[12] = side_length & 0xFF;
		header[13] = (side_length >> 8) & 0xFF;   //take value from the last 8 bits, and ignore all the rest bits       
		header[14] = side_length & 0xFF;
		header[15] = (side_length >> 8) & 0xFF;

		file.write((const char*)header, 18);

		for (int i = 0; i < all_data.size(); i++) {
			file.put(all_data.at(i).blue);
			file.put(all_data.at(i).green);
			file.put(all_data.at(i).red);
		}

		file.close();
	}

	WriteTGA(unsigned int _side_length) : side_length(_side_length){}
	
};


#endif
#ifndef __TGA_FILE_HPP_INCLUDED__
#define __TGA_FILE_HPP_INCLUDED__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class TgaFile {
public:
  TgaFile(unsigned short _side, std::string _filename);
  void write(std::vector<char>  payload);

private:
  unsigned short side;
  std::string filename;

  std::vector<char> header = {
    0,
    0,
    2,                    // 24bit uncompressed RGB
    0, 0, 0, 0, 0,        // mask data
    0, 0,                 // X origin
    0, 0,                 // Y origin
    0, 0,                 // width (lo-hi)
    0, 0,                 // height (lo-hi)
    24,                   // 24bit RGB; 3 bytes per pixel
    0
  };
};

TgaFile::TgaFile(unsigned short _side, std::string _filename) {
  side = _side;
  filename = _filename;

  char side_lo = (char) (side & 0x00FF); // lowed byte
  char side_hi = (char) ((side >> 8) & 0x00FF); // higher byte

  // Set image width = `side`
  header[12] = side_lo;
  header[13] = side_hi;

  // Set image height = `side`
  header[14] = side_lo;
  header[15] = side_hi;
}

void TgaFile::write(std::vector<char> payload) {
  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::binary);

  for (unsigned short i = 0; i < header.size(); ++i) {
    file.put(header[i]);
  }

  for (unsigned short y = 0; y < side; ++y) {
    for (unsigned short x = 0; x < side; ++x) {
      file.put((char) x); // B
      file.put((char) y); // G
      file.put((char) x); // R
    }
  }
  file.close();
}

#endif

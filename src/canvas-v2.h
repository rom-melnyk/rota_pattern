#ifndef __CANVAS_2_H_INCLUDED__
#define __CANVAS_2_H_INCLUDED__

#include <iostream>
#include <vector>

using namespace std;

struct RGB {
  char red;
  char green;
  char blue;
};

class Canvas_v2 {
  private:
    RGB default_color;
    vector<vector<RGB>> all_pixels;
    unsigned short size;

  public:
    /**
     * The class is instantiated with one parameter: the size (width or height) of the canvas.
     */
    Canvas_v2(unsigned short _size) {
      default_color = { 200, 200, 200 };
      size = _size;

      for (unsigned short y = 0; y < size; y++) {
        vector<RGB> line;
        for (unsigned short x = 0; x < size; x++) {
          line.push_back(default_color);
        }
        all_pixels.push_back(line);
      }
    };

    /**
     * Returns all pixels data as 1-dimension array (ready to be saved into TGA or whereever).
     */
    vector<RGB> get_all_pixels() {
      vector<RGB> result;

      for (unsigned short y = 0; y < size; y++) {
        for (unsigned short x = 0; x < size; x++) {
          RGB pixel = all_pixels[y][x];
          result.push_back(pixel);
        }
      }

      return result;
    }

    RGB get_pixel_at(unsigned short x, unsigned short y) {
      return all_pixels[y][x];
    }

    void put_pixel_at(unsigned short x, unsigned short y, RGB color) {
      all_pixels[y][x] = color;
    }
};

#endif

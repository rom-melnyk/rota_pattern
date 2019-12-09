#include <iostream>
#include <vector>

#include "interfaces.hpp"
#include "arguments.hpp"
#include "tga_file.hpp"
#include "pattern_math.hpp"


int main(int argc, char* argv[]) {
  Arguments arguments(argc, argv);
  unsigned short padding = 20;

  TgaFile tga_file(arguments.d_out + 2 * padding, arguments.filename);
  Pattern pattern(arguments.d_out, arguments.d_in, arguments.pen, padding);

  std::cout << "Rotation pattern v1.0.0.\n";
  std::vector<Position> drawing = pattern.create();
  std::cout << "A pattern out of " << drawing.size() << " pixels generated\n";
  std::vector<char> canvas = tga_file.create_canvas(drawing);
  tga_file.write(canvas);
  std::cout << "Created \"" << arguments.filename << "\"\n";

  return 0;
}

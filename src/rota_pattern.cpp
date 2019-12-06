#include <iostream>
#include "arguments.hpp"
#include "tga_file.hpp"


int main(int argc, char* argv[]) {
  Arguments arguments(argc, argv);
  TgaFile tga_file(arguments.d_out + 20, arguments.filename);

  std::cout << "Rotation pattern v1.0.0.\n";
  tga_file.write({});
  std::cout << "Created \"" << arguments.filename << "\"\n";

  return 0;
}

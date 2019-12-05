#include <iostream>
#include "arguments.hpp"


int main(int argc, char* argv[]) {
  Arguments arguments(argc, argv);

  std::cout << "Rotation pattern v1.0.0\n" << arguments.filename << "\n";
  return 0;
}

#ifndef __ARGUMENTS_HPP_INCLUDED__
#define __ARGUMENTS_HPP_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct CliArgument {
  std::string name;
  std::string value;
};

class Arguments {
public:
  int d_out = 500;
  int d_in = 123;
  int pen = 100;
  bool show_help = false;
  std::string filename = "";

  Arguments(int argc, char* argv[]);

private:
  CliArgument parse_argument(std::string arg);
  int to_number(std::string s);
};

Arguments::Arguments(int argc, char* argv[]) {
  std::vector<std::string> help_options = {"--help", "-h", "/?", "h", "?"};

  for (int i = 0; i < argc; ++i) {
    if (std::find(help_options.begin(), help_options.end(), argv[i]) != help_options.end()) {
      show_help = true;
      continue;
    }

    CliArgument parsed = parse_argument(argv[i]);
    // std::cout << "<" << parsed.name << "> = <" << parsed.value << ">\n";

    if (parsed.name == "--dout") {
      d_out = to_number(parsed.value);
    } else if (parsed.name == "--din") {
      d_in = to_number(parsed.value);
    } else if (parsed.name == "--pen") {
      pen = to_number(parsed.value);
    } else if (parsed.name == "--filename") {
      filename = parsed.value;
    }
  }

  if (filename == "") {
    filename = std::to_string(d_out) + "_" + std::to_string(d_in) + "_" + std::to_string(pen) + "_pattern.tga";
  }

  // TODO add field constraints
}

CliArgument Arguments::parse_argument(std::string arg) {
  CliArgument result;
  result.name = arg;
  result.value = "";

  std::string::size_type eq_pos = arg.find("=");
  if (eq_pos != std::string::npos) {
    result.name = arg.substr(0, eq_pos);
    result.value = arg.substr(eq_pos + 1);
  }

  return result;
}

int Arguments::to_number(std::string s) {
  try {
    return std::stoi(s);
  } catch(const std::exception& e) {
    return -1;
  }
}

#endif

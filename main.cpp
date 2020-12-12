#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <fstream>

#include "./header/lexer.hpp"


std::string read_file(const std::string &file_name) {
  std::ifstream ifs(file_name.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

  std::ifstream::pos_type file_size = ifs.tellg();
  ifs.seekg(0, std::ios::beg);

  std::vector<char> source_code(file_size);
  ifs.read(source_code.data(), file_size);

  return std::string(source_code.data(), file_size);
}

int main(int argc, char* argv[]) {
  assert(argc > 1);

  std::string filename(argv[1]);
  std::string input = read_file(filename);

  Lexer lexer;
  lexer.New(input);
}
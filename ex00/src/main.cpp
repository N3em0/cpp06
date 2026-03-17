#include "ScalarConverter.hpp"
#include <sstream>

int main(int argc, char *argv[])
{
  if (argc != 2)
    return (1);
  std::string str = argv[1];
  if (str.empty())
    return 0;
  // float f;
  // double d;
  // int i;
  // std::stringstream fstream(str);
  // std::stringstream dstream(str);
  // std::stringstream istream(str);
  // fstream >> f;
  // dstream >> d;
  // istream >> i;
  //
  // std::cout << f << std::endl;
  // std::cout << d << std::endl;
  // std::cout << i << std::endl;
  ScalarConverter::convert(str);
  return 0;
}

#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Warning: Only one argument" << std::endl;
    return (1);
  }

  std::string str = argv[1];
  if (str.empty())
  {
    std::cout << "Warning: Argument is empty" << std::endl;
    return (1);
  }
  ScalarConverter::convert(str);
  return (0);
}

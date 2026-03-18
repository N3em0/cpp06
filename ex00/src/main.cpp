#include "ScalarConverter.hpp"
#include <climits>

int main(int argc, char *argv[])
{
  if (argc != 2)
    return (1);
  std::string str = argv[1];
  if (str.empty())
    return 0;
  ScalarConverter::convert(str);
  return 0;
}

#include "ScalarConverter.hpp"

#define DISPLAYABLE_CHAR                                                       \
  " !\"#$%'\()*+,-./"                                                          \
  ":;<=>?@[\\]^_`\{|}~"                                                        \
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"

#define CHAR_TO_CONVERT                                                        \
  " !\"#$%'\()*+,-./"                                                          \
  ":;<=>?@[\\]^_`\{|}~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

// static void convertFromChar(char c)
// {
//
// }
//
// static void convertFromInt(int i)
// {
//
// }
//
// static void convertFromFloat(float f)
// {
//
// }
//
// static void convertFromDouble(double d)
// {
//
// }
//
static size_t charCount(char c, std::string str)
{
  size_t count = 0;

  for (size_t i = 0; i < str.length(); ++i)
  {
    if (str[i] == c)
      count++;
  }
  return (count);
}

#include <iostream>

void ScalarConverter::convert(std::string str)
{
  if (str.find_first_not_of(DISPLAYABLE_CHAR) != std::string::npos)
  {
    std::cout << "Error\nNot displayable character inside the string";
  }
  if (str.find_first_not_of(CHAR_TO_CONVERT) == std::string::npos &&
      str.length() == 1)
  {
    std::cout << "c un char" << std::endl;
    return;
  }
  if (str.find_first_not_of("0123456789.f") == std::string::npos)
  {
    if (str.find_first_not_of("0123456789.") == std::string::npos)
    {
      if (str.find_first_not_of("0123456789") == std::string::npos)
      {
        std::cout << "c un int" << std::endl;
        return;
      }
      if (*str.rbegin() != '.' && charCount('.', str) == 1)
      {
        std::cout << "c un double" << std::endl;
        return;
      }
    }
    std::cout << *str.rbegin() << std::endl;
    if (*str.rbegin() == 'f' && isdigit(*(str.rbegin() + 1)) &&
        charCount('.', str) == 1 && charCount('f', str))
    {
      std::cout << "c un float" << std::endl;
      return;
    }
  }
  std::cout << "ya rien" << std::endl;
}

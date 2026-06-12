#include "ScalarConverter.hpp"
#include <climits> //INT_MIN & INT_MAX
#include <cmath>   //isinf()
#include <cstdlib> // std::strtod()
#include <iomanip> //std::setprecision()
#include <iostream>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
  if (this != &rhs)
  {
  }
  return (*this);
}

static void displayValues(int i, float f, double d)
{
  if (i > INT_MIN && i <= INT_MAX)
    std::cout << "int: " << i << std::endl;
  else
    std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convertFromChar(std::string str)
{
  char c;
  int i;
  float f;
  double d;

  c = str[0];
  if (c >= 32 && c < 127)
    std::cout << "char: \'" << c << "\'" << std::endl;
  else if ((c >= 0 && c < 32) || c == 127)
    std::cout << "char: Non displayable" << std::endl;
  i = static_cast<int>(c);
  f = static_cast<float>(c);
  d = static_cast<double>(c);
  displayValues(i, d, f);
  return;
}

static void convertFromInt(std::string str)
{
  double tmp;

  tmp = std::strtod(str.c_str(), NULL);
  if (tmp < INT_MIN || tmp > INT_MAX)
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
  else
  {
    int i = std::atoi(str.c_str());
    if (i > CHAR_MAX || i < 0)
      std::cout << "char: impossible" << std::endl;
    else if (i >= 32 && i < 127)
      std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
    else if ((i >= 0 && i < 32) || i == 127)
      std::cout << "char: Non displayable" << std::endl;
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    displayValues(i, f, d);
  }
}

static void convertFromFloat(std::string str)
{
  float f;
  int i;
  double d;

  f = std::strtof(str.c_str(), NULL);
  if (isinf(f))
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << (f >= 0 ? "+" : "") << f << "f" << std::endl;
    std::cout << "double: " << (f >= 0 ? "+" : "") << static_cast<double>(f)
              << std::endl;
  }
  else
  {
    if (f > CHAR_MAX || f < 0)
      std::cout << "char: impossible" << std::endl;
    else if (f >= 32 && f < 127)
      std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;
    else if ((f >= 0 && f < 32) || f == 127)
      std::cout << "char: Non displayable" << std::endl;
    i = static_cast<int>(f);
    d = static_cast<double>(f);
    displayValues(i, f, d);
  }
}

static void convertFromDouble(std::string str)
{
  double d;
  int i;
  float f;

  d = std::strtod(str.c_str(), NULL);
  if (isinf(d))
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << (d >= 0 ? "+" : "") << static_cast<float>(d)
              << "f" << std::endl;
    std::cout << "double: " << (d >= 0 ? "+" : "") << d << std::endl;
  }
  else
  {
    if (d > CHAR_MAX || d < 0)
      std::cout << "char: impossible" << std::endl;
    else if (d >= 32 && d < 127)
      std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
    else if ((d >= 0 && d < 32) || d == 127)
      std::cout << "char: Non displayable" << std::endl;
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    displayValues(i, f, d);
  }
}

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

void ScalarConverter::convert(std::string str)
{
  if (!str.compare("+inff") || !str.compare("-inff") || !str.compare("inff") ||
      !str.compare("nanf") || !str.compare("-nanf"))
  {
    convertFromFloat(str);
    return;
  }
  if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("inf") ||
      !str.compare("nan") || !str.compare("-nan"))
  {
    convertFromDouble(str);
    return;
  }
  if (str.length() == 1 && (str[0] < 48 || str[0] > 57))
  {
    convertFromChar(str);
    return;
  }
  if (str.find_first_of('-', 1) != std::string::npos)
  {
    std::cout << "a" << std::endl;
    return;
  }
  if (str.find_first_not_of("-0123456789.f") == std::string::npos)
  {
    if (str.find_first_not_of("-0123456789.") == std::string::npos)
    {
      if (str.find_first_not_of("-0123456789") == std::string::npos)
      {
        convertFromInt(str);
        return;
      }
      if (*str.rbegin() != '.' && charCount('.', str) == 1)
      {
        convertFromDouble(str);
        return;
      }
    }
    if (*str.rbegin() == 'f' && isdigit(*(str.rbegin() + 1)) &&
        charCount('.', str) == 1 && charCount('f', str) == 1)
    {
      convertFromFloat(str);
      return;
    }
  }
  std::cout << "Warning: invalid input. Can't convert" << std::endl;
}

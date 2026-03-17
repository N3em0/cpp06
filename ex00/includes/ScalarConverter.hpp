#pragma once

#include <bits/stdc++.h>

class ScalarConverter
{
public:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  virtual ~ScalarConverter() = 0;

  ScalarConverter &operator=(ScalarConverter const &rhs);

  static void convert(std::string str);
};

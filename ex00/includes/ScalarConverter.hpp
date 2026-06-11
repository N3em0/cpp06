#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ScalarConverter &operator=(ScalarConverter const &rhs);

public:
  virtual ~ScalarConverter() = 0;

  static void convert(std::string str);
};

#endif

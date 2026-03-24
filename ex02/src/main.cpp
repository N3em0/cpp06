#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <typeinfo>

Base *generate(void)
{
  srand(static_cast<unsigned int>(time(0)));
  int i = rand() % 3 + 1;
  switch (i)
  {
  case 1:
    return (new A);
  case 2:
    return (new B);
  case 3:
    return (new C);
  default:
    return 0;
  }
}

void Identify(Base *p)
{
  if (dynamic_cast<A *>(p) != 0)
  {
    std::cout << "object pointed is type A" << std::endl;
    return;
  }
  if (dynamic_cast<B *>(p) != 0)
  {
    std::cout << "object pointed is type B" << std::endl;
    return;
  }
  if (dynamic_cast<C *>(p) != 0)
  {
    std::cout << "object pointed is type C" << std::endl;
    return;
  }
  else
  {
    std::cout << "object is NULL" << std::endl;
  }
}

void Identify(Base &p)
{
  try
  {
    A a = dynamic_cast<A &>(p);
    std::cout << "object referenced is type A" << std::endl;
    return;
  }
  catch (std::bad_cast &e)
  {
    std::cout << e.what() << std::endl;
  }
  try
  {
    B b = dynamic_cast<B &>(p);
    std::cout << "object referenced is type B" << std::endl;
    return;
  }
  catch (std::bad_cast &e)
  {
    std::cout << e.what() << std::endl;
  }
  try
  {
    C c = dynamic_cast<C &>(p);
    std::cout << "object referenced is type C" << std::endl;
    return;
  }
  catch (std::bad_cast &e)
  {
    std::cout << e.what() << std::endl;
  }
}

int main()
{
  Base *b;

  b = generate();
  Identify(b);
  Identify(*b);

  // Base *n = 0;
  // Identify(n);
  // Identify(*n);

  delete b;
}

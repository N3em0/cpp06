#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void)
{
  srand(static_cast<unsigned int>(time(0))); // Seed once
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
  if (dynamic_cast<A &>(p) != 0)
  {
    std::cout << "object pointed is type A" << std::endl;
    return;
  }
  if (dynamic_cast<B &>(p) != 0)
  {
    std::cout << "object pointed is type B" << std::endl;
    return;
  }
  if (dynamic_cast<C &>(p) != 0)
  {
    std::cout << "object pointed is type C" << std::endl;
    return;
  }
  else
  {
    std::cout << "object is NULL" << std::endl;
  }
}

int main()
{
  Base *b;
  Base *n = 0;

  b = generate();
  Identify(b);
  Identify(n);

  std::cout << &b << std::endl;
  delete b;
}

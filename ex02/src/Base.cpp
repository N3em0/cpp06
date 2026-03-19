#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

// Base *generate(void)
// {
//   srand(static_cast<unsigned int>(time(0))); // Seed once
//   int i = rand() % 3 + 1;
//   switch (i)
//   {
//   case 1:
//     return (new A);
//   case 2:
//     return (new B);
//   case 3:
//     return (new C);
//   default:
//     return 0;
//   }
// }

// void Identify(Base *p)
// {
//   if (dynamic_cast<A *>(p) != 0)
//   {
//     std::cout << "type A" << std::endl;
//     return;
//   }
//   if (dynamic_cast<B *>(p) != 0)
//   {
//     std::cout << "type B" << std::endl;
//     return;
//   }
//   if (dynamic_cast<C *>(p) != 0)
//   {
//     std::cout << "type C" << std::endl;
//     return;
//   }
// }
//
// void Identify(Base &p) { (void)p; }

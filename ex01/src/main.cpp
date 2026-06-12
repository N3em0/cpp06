#include "Data.hpp"
#include "Serialize.hpp"
#include <iostream>
#include <stdint.h> //uintptr_t

int main()
{
  uintptr_t i;
  int j;

  std::cout << "\n======= TYPES SIZE ===============================\n";
  std::cout << "uintptr_t                   : " << sizeof(uintptr_t)
            << std::endl;
  std::cout << "int                         : " << sizeof(int) << std::endl;
  std::cout << "Data                        : " << sizeof(Data *) << std::endl;

  std::cout << "\n======= STACK ====================================\n";
  Data ptr1;
  {};

  std::cout << "ptr1 base address           : " << &ptr1 << std::endl;
  i = Serialize::serialize(&ptr1);
  j = Serialize::serialize(&ptr1);
  std::cout << "ptr1 addr as uintptr1_t (i) : " << i << std::endl;
  std::cout << "ptr1 addr as int (j)        : " << j << std::endl;
  std::cout << "ptr1 addr deserialized i    : " << Serialize::deserialize(i)
            << std::endl;
  std::cout << "ptr1 addr deserialized j    : " << Serialize::deserialize(j)
            << std::endl;

  std::cout << "\n======== HEAP ====================================\n";
  Data *ptr2;

  ptr2 = new Data;
  std::cout << "ptr2 base address           : " << ptr2 << std::endl;
  i = Serialize::serialize(ptr2);
  j = Serialize::serialize(ptr2);
  std::cout << "ptr2 addr as uintptr2_t (i) : " << i << std::endl;
  std::cout << "ptr2 addr as int (j)        : " << j << std::endl;
  std::cout << "ptr2 addr deserialized i    : " << Serialize::deserialize(i)
            << std::endl;
  std::cout << "ptr2 addr deserialized j    : " << Serialize::deserialize(j)
            << std::endl;
  delete ptr2;
}

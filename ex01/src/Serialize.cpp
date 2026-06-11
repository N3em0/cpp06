#include "Serialize.hpp"
#include "Data.hpp"
#include <stdint.h>

Serialize::Serialize() {}

Serialize::Serialize(const Serialize &src) { (void)src; }

Serialize &Serialize::operator=(const Serialize &rhs)
{
  if (this != &rhs)
  {
  }
  return (*this);
}

uintptr_t Serialize::serialize(Data *ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw)
{
  return (reinterpret_cast<Data *>(raw));
}

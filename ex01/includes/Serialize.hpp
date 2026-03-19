#pragma once

#include <stdint.h>
struct Data;

class Serialize
{
public:
  Serialize();
  Serialize(Serialize const &src);
  virtual ~Serialize() = 0;

  Serialize &operator=(Serialize const &rhs);

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

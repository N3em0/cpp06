#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>
struct Data;

class Serialize
{
private:
  Serialize();
  Serialize(Serialize const &src);
  Serialize &operator=(Serialize const &rhs);

public:
  virtual ~Serialize() = 0;

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif

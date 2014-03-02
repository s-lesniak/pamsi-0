/*! @file tabliczb.cpp
 * @brief Definicje metod klasy TabLiczb */

#include "tabliczb.hh"

using namespace std;

bool TabLiczb::operator == (const TabLiczb& druga)
{
  unsigned roz = size();
  if (roz != druga.size())
    return false;

  for (unsigned i = 0; i < roz; i++) {
    if ((at(i) != druga.at(i)))
      return false;
  } 
  return true;
}

void TabLiczb::RazyDwa()
{
  for (unsigned i = 0; i < size(); i++) {
    this->at(i) *= 2;
  }
}

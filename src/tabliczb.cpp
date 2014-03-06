/*! @file tabliczb.cpp
 * @brief Definicje metod klasy TabLiczb */
#include <iostream>

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

bool TabLiczb::ZamienElementy(unsigned i, unsigned j)
{
  if (i > size() || j > size()) {
    cerr << "Nieprawidłowy indeks przy zamienianiu elementów tablicy"
	 << endl;
    return false;
  }

  int tmp = at(i);

  at(i) = at(j);
  at(j) = tmp;

  return true;
}

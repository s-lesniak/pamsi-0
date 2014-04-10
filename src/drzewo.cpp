/*! \file drzewo.cpp
 * \brief Definicje metod klasy Drzewo */

#include "elemdrzewa.hh"
#include "drzewo.hh"

template <typename T>
void Drzewo<T>::Dodaj (const T& elem)
{
  ElemDrzewa<T> *nowy = new ElemDrzewa<T>;
}

template class Drzewo<int>;

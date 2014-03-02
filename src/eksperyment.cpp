/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>

#include "eksperyment.hh"

using namespace std;

Eksperyment::Eksperyment(string PlikWyj): NazwaWyjscia(PlikWyj)
{
  if (!SpiszZadania())
    return;
}

bool Eksperyment::WczytajPliki (unsigned nr)
{
  return true;
}

bool Eksperyment::SpiszZadania ()
{
  unsigned n;
  cout << "Podaj liczbę plików wejściowych: ";
  cin >> n;
  if (cin.fail()) {
    cerr << "To nie jest liczba" << endl;
    return false;
  }
  Zadania.resize(n);

  for (int i = 0; i < n; i++) {
    
}

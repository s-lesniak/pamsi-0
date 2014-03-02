/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>
#include <fstream>

#include "eksperyment.hh"

using namespace std;

bool SprawdzNazwe(string nazwa)
{
  ifstream str(nazwa.c_str());

  if (!(str.is_open())) {
    cerr << "Pliku " << nazwa << "nie udało się otworzyć" << endl;
    return false;
  }
  else
    return true;
}

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
  unsigned n, k;
  cout << "Podaj liczbę plików wejściowych: ";
  cin >> n;
  if (cin.fail()) {
    cerr << "To nie jest liczba" << endl;
    return false;
  }
  Zadania.resize(n);

  for (unsigned i = 0; i < n; i++) {
    cout << "Podaj plik źródłowy nr " << (i+1) << ": "; 
    if (!(cin >> Zadania[i].PlikWejsciowy)) return false;
    if (!SprawdzNazwe(Zadania[i].PlikWejsciowy)) return false;
    cout << "Podaj plik wzorcowy nr " << (i+1) << ": ";
    if (!(cin >> Zadania[i].PlikWzorcowy)) return false;
    if (!SprawdzNazwe(Zadania[i].PlikWzorcowy)) return false;
    cout << "Ilość badań pliku nr " << (i+1) << ": ";
    cin >> Zadania[i].IleRazy;
    if (cin.fail()) {
      cerr << "To nie jest liczba" << endl;
      return false;
    }
  }
}

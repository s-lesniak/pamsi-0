/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>
#include <fstream>

#include "eksperyment.hh"
#include "czas.hh"

using namespace std;

bool SprawdzNazwe(string nazwa)
{
  ifstream str(nazwa.c_str());

  if (!(str.is_open())) {
    cerr << "Pliku " << nazwa << " nie udało się otworzyć\n";
    return false;
  }
  else
    return true;
}

Eksperyment::Eksperyment(string PlikWyj): NazwaWyjscia(PlikWyj)
{
  if (!SpiszZadania())
    return;
  
  for (unsigned int i = 0; i < Zadania.size(); i++) {
    float sr = WielokrotnyPomiar(i);    
    WynikBadania elem = {Wejscie.size(), Zadania[i].IleRazy, sr};
    Wyniki.push_back(elem);
  }
  Zapisz();
}

bool Eksperyment::WczytajPliki (unsigned nr)
{
  if (WczytajJedenPlik(Zadania[nr].PlikWejsciowy, Wejscie)) {
      if (WczytajJedenPlik(Zadania[nr].PlikWzorcowy, Wzor))
	return true;
      else return false;
    }
  else return false;
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
  return true;
}

bool Eksperyment::WczytajJedenPlik(string nazwa, TabLiczb& tab)
{
  ifstream strum(nazwa.c_str());

  unsigned rozm;
  if (!(strum >> rozm)) {
    cerr << "Błąd w linii 1 pliku " << nazwa << "!\n";
    return false;
  }
  tab.resize(0);

  int num;
  if (!(strum >> num)) {
    cerr << "Brak liczb w pliku " << nazwa << "!\n";
    return false;
  }
  while (strum.good()) {
    tab.push_back(num);
    if (!(strum >> num) && !strum.eof()) {
      cerr << "Błąd w linii " << tab.size() << " w pliku " << nazwa
	   << "!\n";
      return false;
    }
  }

  if (tab.size() == rozm)
    return true;
  else {
    cerr << "Błędna ilość liczb w pliku " << nazwa << "!\n";
    return false;
  }
}

float Eksperyment::WielokrotnyPomiar(unsigned nr)
{
  unsigned ile = Zadania[nr].IleRazy;
  float wynik = 0.0;
  timespec przed, po;

  for (unsigned i = 0; i < ile; i++) {
    if(!WczytajPliki(nr)) 
      return -1.0;
    przed = Teraz();
    Wejscie.RazyDwa();
    po = Teraz();
    if(!(Wejscie == Wzor))
      return -1.0;
    wynik += RoznicaCzasu(przed, po);
  }

  wynik /= ile;

  return wynik;
}

void Eksperyment::Zapisz()
{
  ofstream str;
  str.open(NazwaWyjscia.c_str());
  str << "Ilość liczb,Ilość próbek,Średni czas\n";
  for (unsigned i = 0; i < Wyniki.size(); i++) {
    str << Wyniki[i].IloscLiczb << ',' << Wyniki[i].IloscDzialan
	<< ',' << Wyniki[i].SredniCzas << '\n';
  }

  str.close();
}

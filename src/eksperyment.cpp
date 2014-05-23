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
  return (WczytajJedenPlik(Zadania[nr].PlikWejsciowy, Wejscie));
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
    cout << "Ilość badań pliku nr " << (i+1) << ": ";
    cin >> Zadania[i].IleRazy;
    if (cin.fail()) {
      cerr << "To nie jest liczba" << endl;
      return false;
    }
  }
  return true;
}

bool Eksperyment::WczytajJedenPlik(const string& nazwa, TabStr& tab)
{
  ifstream strum(nazwa.c_str());

  unsigned rozm;
  if (!(strum >> rozm)) {
    cerr << "Błąd w linii 1 pliku " << nazwa << "!\n";
    return false;
  }
  tab.resize(0);

  string napis;
  if (!(strum >> napis)) {
    cerr << "Brak napisów w pliku " << nazwa << "!\n";
    return false;
  }
  while (strum.good()) {
    tab.push_back(napis);
    if (!(strum >> napis) && !strum.eof()) {
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

	if(!WczytajPliki(nr))
		return -1.0;

	BadObiekt *ob = Przygotuj();
	for (unsigned i = 0; i < ile; i++) {
		wynik += BadanaAkcja(ob, i);
	}

	wynik /= ile;

	delete ob;
  return wynik;
}

void Eksperyment::Zapisz()
{
  ofstream str;
  str.open(NazwaWyjscia.c_str());
  str << "Ilość napisów, Ilość badań, Średni czas\n";
  for (unsigned i = 0; i < Wyniki.size(); i++) {
    str << Wyniki[i].IloscLiczb << ", " << Wyniki[i].IloscDzialan
	<< ", " << Wyniki[i].SredniCzas << '\n';
  }

  str.close();
}

BadObiekt* Eksperyment::Przygotuj()
{
	unsigned rozm = Wejscie.size() * 10;
	BadObiekt* obiekt = new BadObiekt(rozm);
	for (unsigned i = 0; i < Wejscie.size(); i++)
		(*obiekt)[Wejscie[i]];

	return obiekt;
}

double Eksperyment::BadanaAkcja(BadObiekt* obiekt, unsigned i) const
{
	timespec przed, po;
	float wynik = 0;
	for (unsigned i = 0; i < Wejscie.size(); i++) {
		przed = Teraz();
		(*obiekt)[Wejscie[i]] = 3.14;
		po = Teraz();

		wynik += RoznicaCzasu(przed, po);
	}
	return wynik / Wejscie.size();
}

bool Zapytaj()
{
  cout << "Czy chcesz sortować z optymalizacją? (t/n) ";
  char c;
  while(1) {
    cin >> c;
    switch(c) {
    case 't': 
    case 'T':
      return true;
    case 'n':
    case 'N':
      return false;
    default:
      break;
    }
  }
  return false;
}

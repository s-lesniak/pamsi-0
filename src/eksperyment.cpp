/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>
#include <fstream>

#include "eksperyment.hh"
#include "czas.hh"

using namespace std;

//extern const float ZAPELNIENIE;

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
//  if (!SpiszZadania())
//    return;
//
//  for (unsigned int i = 0; i < Zadania.size(); i++) {
//    float sr = WielokrotnyPomiar(i);
//    WynikBadania elem = {Wejscie.size(), Zadania[i].IleRazy, sr};
//    Wyniki.push_back(elem);
//  }
//  Zapisz();
	Mapa.WczytajWierzcholki();
	Mapa.WczytajKrawedzie();

	SpiszZadania();

	for (unsigned i = 0; i < Zadania.size(); i++) {
		unsigned start = Mapa.Znajdz(Zadania[i].Start),
				koniec = Mapa.Znajdz(Zadania[i].Koniec);

		timespec pocz = Teraz();
		vector<unsigned> wynik_bfs =
				Mapa.BFS(start, koniec);
		timespec po_bfs = Teraz();
		vector<unsigned> wynik_dfs =
				Mapa.DFS(start, koniec);
		timespec po_dfs = Teraz();
		vector<unsigned> wynik_a =
				Mapa.AStar(start, koniec);
		timespec po_a = Teraz();

		float czas_bfs = RoznicaCzasu(pocz, po_bfs),
				czas_dfs = RoznicaCzasu(po_bfs, po_dfs),
				czas_a = RoznicaCzasu(po_dfs, po_a);

		WynikBadania elem = {Zadania[i].Start, Zadania[i].Koniec,
				czas_bfs, Mapa.LacznyKoszt(wynik_bfs),
				czas_dfs, Mapa.LacznyKoszt(wynik_dfs),
				czas_a, Mapa.LacznyKoszt(wynik_a)};
		Wyniki.push_back(elem);
		};
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

void Eksperyment::Zapisz()
{
  ofstream str;
  str.open(NazwaWyjscia.c_str());
  str << "Punkt początkowy,Punkt końcowy,Czas BFS,Koszt BFS,Czas DFS,"
		  << "Koszt DFS,Czas A*,Koszt A*\n";
  for (unsigned i = 0; i < Wyniki.size(); i++) {
    str << Wyniki[i].Start << "," << Wyniki[i].Stop << ", "
    		<< Wyniki[i].BFS_czas << ',' << Wyniki[i].BFS_koszt << ','
    		<< Wyniki[i].DFS_czas << ',' << Wyniki[i].DFS_koszt << ','
    		<< Wyniki[i].A_czas << ',' << Wyniki[i].A_koszt << '\n';
  }

  str.close();
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

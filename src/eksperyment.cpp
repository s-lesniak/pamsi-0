/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>
#include <fstream>
#include <exception>
#include <limits>

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

	for (unsigned i = 0; i < Mapa.Wezly.size(); i++)
		cout << Mapa.Wezly[i];

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

void Eksperyment::SpiszZadania()
{
	unsigned n;
	cout << "Podaj liczbę tras do znalezienia: ";
	while (!(cin >> n)) {
		cout << "Nieprawidłowa liczba, podaj ją ponownie: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	Zadania.resize(n);

	for (unsigned i = 0; i < n; i++) {
		cout << "Podaj punkt startowy nr " << (i+1) << ": ";
		while (1) {
			string nazwa;
//			getline(cin, nazwa);
			cin >> nazwa;
			try {
				Mapa.Znajdz(nazwa);
				Zadania[i].Start = nazwa;
				break;
			}
			catch (const exception &e)
			{ cerr << "Nie ma punktu o nazwie " << nazwa << endl; }
		}
		cout << "Podaj punkt końcowy nr " << (i+1) << ": ";
		while (1) {
			getline(cin, Zadania[i].Koniec);
			try {
				Mapa.Znajdz(Zadania[i].Koniec);
				break;
			}
			catch (const exception &e)
			{ cerr << "Nie ma punktu o nazwie " << Zadania[i].Koniec; }
		}
	}
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

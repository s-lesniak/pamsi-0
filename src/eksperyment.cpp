/*! @file eksperyment.cpp
 * @brief Definicje metod klasy Eksperyment */
#include <iostream>
#include <fstream>
#include <exception>
#include <limits>

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
	Mapa.WczytajWierzcholki();
	Mapa.WczytajKrawedzie();

	SpiszZadania();

	for (unsigned i = 0; i < Zadania.size(); i++) {
		unsigned start = Mapa.Znajdz(Zadania[i].Start),
				koniec = Mapa.Znajdz(Zadania[i].Koniec);

		timespec pocz = Teraz();
//		vector<unsigned> wynik_tsp = Mapa.TSP(start);
		timespec kon = Teraz();

		cout << "Trasa nr " << i+1 << ": ";

		float czas = RoznicaCzasu(pocz, kon);

//		WynikBadania elem = {Zadania[i].Start, czas,
//				Mapa.LacznyKoszt(wynik_tsp)};
//		Wyniki.push_back(elem);
		}
	Zapisz();
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (unsigned i = 0; i < n; i++) {
		cout << "Podaj punkt startowy nr " << (i+1) << ": ";
		while (1) {
			string nazwa;
			getline(cin, nazwa);
//			cin >> noskipws >> nazwa;
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
			{ cerr << "Nie ma punktu o nazwie " << Zadania[i].Koniec
				<< endl; }
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
//    str << Wyniki[i].Start << "," << Wyniki[i].Stop << ','
//    		<< Wyniki[i].BFS_czas << ',' << Wyniki[i].BFS_koszt << ','
//    		<< Wyniki[i].DFS_czas << ',' << Wyniki[i].DFS_koszt << ','
//    		<< Wyniki[i].A_czas << ',' << Wyniki[i].A_koszt << '\n';
  }

  str.close();
}

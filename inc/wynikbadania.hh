/*! @file wynikbadania.hh
 * @brief Deklaracja struktury WynikiBadania */

#ifndef WYNIKBADANIA_HH
#define WYNIKBADANIA_HH

#include <string>

using namespace std;
/*!
 * @brief Wynik badania pojedynczego pliku z liczbami
 *
 * Struktura służy do przekazania informacji nt. jednokrotnego badania
 * pojedynczego przejścia grafu. Zawiera on kolejno: początek i koniec
 * przejścia grafu, oraz parami zebrane: czas wykonania oraz łączny koszt
 * przejścia, kolejno alogrytmami: BFS, DFS i A*. */
struct WynikBadania {
	string Start, Stop;

	double BFS_czas, BFS_koszt,
	DFS_czas, DFS_koszt,
	A_czas, A_koszt;
};

#endif

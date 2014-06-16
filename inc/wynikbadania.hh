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
 * pełnego przejścia grafu. Zawiera on kolejno: początek przejścia grafu,
 * oraz czas wykonania oraz łączny koszt znalezionej  */
struct WynikBadania {
	string Start;

	double czas, koszt;
};

#endif

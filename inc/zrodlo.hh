/*! @file
 * @brief Deklaracja struktury Zrodlo */
#include <string>

#ifndef ZRODLO_HH
#define ZRODLO_HH

using namespace std;

/*! 
 * @brief Informacje o źródle pojedynczego badania 
 *
 * Pojedynczym badaniem jest przejście grafu pomiędzy dwoma zadanymi
 * punktami. Poniższa struktura zapamiętuje te właśnie punkty.*/
struct Zrodlo {
	/*!
	 * Nazwa punktu początkowego
	 */
	string Start;

	/*!
	 * Nazwa punktu końcowego
	 */
	string Koniec;
};

#endif

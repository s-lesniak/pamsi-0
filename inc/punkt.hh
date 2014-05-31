/*!
 * \file punkt.hh
 *
 *  Created on: 29 maj 2014
 *      Author: szymon
 */

#ifndef PUNKT_HH_
#define PUNKT_HH_

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*!
 * Współczynnik konwersji stopni na radiany.
 */
const float DEG2RAD = 0.0349065850398866;

/*!
 * Wyrażona w kilometrach długość 1 stopnia długości geograficznej,
 * alternatywnie 60 mil morskich.
 */
const float DEG2KM = 111.195;

/*!
 * Maksymalna długość nazwy dopuszczona do wpisania operatorem >>.
 */
const unsigned MAX_DL = 50;

/*!
 * \brief Punkt na kuli ziemskiej
 *
 * Struktura modeluje punkt na kuli ziemskiej. Opisana jest dwoma
 * współrzędnymi geograficznymi, nadana jest mu nazwa.
 */
struct Punkt {

	/*!
	 * \brief Charakterystyczna nazwa punktu
	 */
	string Nazwa;

	/*!
	 * \brief Szerokość geograficzna
	 *
	 * Pole a sens tylko wtedy, gdy jest z zakresu [-90; 90].
	 * Wartości dodatnie odpowiadają półkuli północnej, a ujemne -
	 * południowej.
	 */
	float szer;

	/*!
	 * \brief Długość geograficzna
	 *
	 * Pole ma sens tylko wtedy, gdy jest z zakresu [-180; 180].
	 * Wartości dodatnie odpowiadają półkuli wschodniej, a ujemne -
	 * zachodniej.
	 */
	float dl;

	/*!
	 * \brief Oblicza dystans między dwoma punktami
	 *
	 * Wzór w funkcji działa przy założeniu, że Ziemia jest idealnie
	 * kulista, w nawigacji nazywany jest wzorem na długość ortodromy.
	 * Działanie wzoru dla nonsensownych wartości współrzędnych punktów
	 * nie było sprawdzane.
	 *
	 * @return Długość najkrótszej drogi między punktami na kuli, w
	 * kilometrach.
	 */
	double OdlegloscDo(const Punkt &cel)
	{
		float rozn = dl - cel.dl;
		return DEG2KM * (acos((sin(DEG2RAD*szer) * sin(DEG2RAD*cel.szer)) +
				(cos(DEG2RAD*szer) * cos(DEG2RAD*cel.szer) * cos(DEG2RAD*rozn))) /
				DEG2RAD);
	}
};

/*!
 * \brief Wypisanie informacji o punkcie.
 *
 * Format wypisu \b nie jest zgodny z formatem zapisu operatorem >>, i
 * jest postaci:
 * \verbatim nazwa: szer dl \endverbatim
 * @param str - strumień do wypisania
 * @param p - punkt do wypisania
 * @return strumień, na którym działano
 */
ostream& operator << (ostream& str, const Punkt &p);

/*!
 * \brief Sczytuje informacje o punkcie.
 *
 * Informacje o punkcie muszą się znaleźć w jednym wierszu (tzn. być
 * zakończone znakiem nowej linii. W linii, oddzielone przecinkami bez
 * spacji, mają być zapisane odpowiednio: nazwa, szerokość i długość
 * geograficzna. Maksymalna długość wczytywanej nazwy jest zapisana w
 * stałej MAX_DL.
 *
 * @param str - strumień, z którego sczytujemy
 * @param p - punkt, który chcemy wyedytować
 * @return strumień, na którym działano
 */
istream& operator >> (istream& str, Punkt &p);

#endif /* PUNKT_HH_ */

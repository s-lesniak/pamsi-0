/*!
 * \file punkt.hh
 *
 *  Created on: 29 maj 2014
 *      Author: szymon
 */

#ifndef PUNKT_HH_
#define PUNKT_HH_

#include <string>

using namespace std;

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
	 * \brief Długość geograficzna
	 *
	 * Pole ma sens tylko wtedy, gdy jest z zakresu [-180; 180].
	 * Wartości dodatnie odpowiadają półkuli wschodniej, a ujemne -
	 * zachodniej.
	 */
	float dl;

	/*!
	 * \brief Szerokość geograficzna
	 *
	 * Pole a sens tylko wtedy, gdy jest z zakresu [-90; 90].
	 * Wartości dodatnie odpowiadają półkuli północnej, a ujemne -
	 * południowej.
	 */
	float szer;
};


#endif /* PUNKT_HH_ */

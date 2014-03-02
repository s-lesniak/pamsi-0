/*! @file czas.hh
 * @brief Deklaracje funkcji związanych z pomiarem czasu */

#ifndef CZAS_HH
#define CZAS_HH

#include <ctime>

/*!
 * @brief Podaje bieżący czas systemowy 
 *
 * @return Obecne wskazanie zegara CLOCK_REALTIME */
struct timespec Teraz();

/*!
 * @brief Różnica czasu
 *
 * Funkcja oblicza różnicę czasu pomiędzy dwoma zadanymi chwilami i 
 * konwertuje wynik na przyjazną dla człowieka formę
 *
 * @param[in] przed - wcześniejsza chwila czasu
 * @param[in] po - późniejsza chwila czasu
 * @return różnica pomiędzy chwilami */
float RoznicaCzasu (struct timespec przed, struct timespec po);

#endif

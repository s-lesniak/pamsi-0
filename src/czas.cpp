/*! @file czas.cpp
 * @brief Definicje funkcji związanych z pomiarem czasu */

#include "czas.hh"

struct timespec Teraz()
{
  struct timespec wynik = {0, 0};
  clock_gettime(CLOCK_REALTIME, &wynik);

  return wynik;
}

float RoznicaCzasu (struct timespec przed, struct timespec po)
{
  return (po.tv_sec-przed.tv_sec + (po.tv_nsec-przed.tv_nsec) /
	  ((float) 1.0e9));
}

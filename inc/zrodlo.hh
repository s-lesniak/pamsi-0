/*! @file
 * @brief Deklaracja struktury Zrodlo */
#include <string>

#ifndef ZRODLO_HH
#define ZRODLO_HH

using namespace std;

/*! 
 * @brief Informacje o źródle pojedynczego badania 
 *
 * Dla poprawnego działania programu należy dostarczyć mu plik o
 * następującej strukturze:
 * W pierwszym wierszu zapisana jest pewna ilość liczb. W następnych 
 * wierszach pojawiają się, napisy. Ma być ich dokładnie tyle, ile
 * zapisano w pierwszym wierszu. */
struct Zrodlo {
  /*!
   * @brief Nazwa pliku źródłowego
   *
   * Z pliku o tej nazwie sczytane zostaną napisy będące źródłem
   * badania. */
  string PlikWejsciowy;

  /*!
   * @brief Ilość powtórzeń badania
   *
   * Tę ilość razy zostanie wykonane badanie na zadanym zbiorze liczb.
   * Co za tym idzie, jest to też liczba danych, z której zostanie 
   * wyliczona wartość średnia. */
  unsigned IleRazy;
};

#endif

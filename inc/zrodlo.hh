/*! @file
 * @brief Deklaracja struktury Zrodlo */
#include <string>

#ifndef ZRODLO_HH
#define ZRODLO_HH

using namespace std;

/*! 
 * @brief Informacje o źródle pojedynczego badania 
 *
 * Dla poprawnego działania programu należy dostarczyć mu dwa pliki o 
 * następującej strukturze:
 * W pierwszym wierszu zapisana jest pewna ilość liczb. W następnych 
 * wierszach pojawiają się, po jednej, liczby całkowite. Ma być ich 
 * dokładnie tyle, ile zapisano w pierwszym wierszu. 
 *
 * Ponadto drugi plik ma zawierać takie liczby, na jakie powinny być 
 * przekształcone liczby z pierwszego pliku. Ma to na celu sprawdzenie
 * prawidłowości działania programu. */
struct Zrodlo {
  /*!
   * @brief Nazwa pliku źródłowego
   *
   * Z pliku o tej nazwie sczytane zostaną liczby będące źródłem 
   * badania. */
  string PlikWejsciowy;

  /*!
   * @brief Nazwa pliku wzorcowego
   *
   * Liczby z pliku o tej nazwie zostaną porównane z przetworzonymi
   * liczbami z pierwszego pliku. */
};

#endif

/*! @file wynikbadania.hh
 * @brief Deklaracja struktury WynikiBadania */

#ifndef WYNIKBADANIA_HH
#define WYNIKBADANIA_HH

/*!
 * @brief Wynik badania pojedynczego pliku z liczbami
 *
 * Struktura służy do przekazania informacji nt. wielokrotnego badania
 * zbioru liczb z jednego pliku. */
struct WynikBadania {
  /*!
   * @brief Ilość liczb, jaka znajdowała się w badanym pliku */
  unsigned IloscLiczb;

  /*!
   * @brief Ilość razy, jaką badano wczytaną bazę liczb */
  unsigned IloscDzialan;

  /*!
   * @brief Średni wynik
   *
   * Średni czas, w jakim na zbiorze liczb wykonano zadaną operację. 
   * Podany w sekundach */
  float SredniCzas;
};

#endif

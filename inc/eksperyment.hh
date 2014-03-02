/*! @file eksperyment.hh
 * @brief Deklaracja klasy Eksperyment, głównej w programie */

#ifndef EKSPERYMENT_HH
#define EKSPERYMENT_HH

#include <string>
#include <vector>

using namespace std;

/*!
 * @brief Główna klasa programu, modeluje całość badanie zbioru liczb
 *
 * Klasa obsługuje badanie czasu, w jakim dokona się jakaś akcja na 
 * zbiorze liczb. Liczby muszą być zapisane w plikach; musi też istnieć
 * plik wzorcowy służący do sprawdzenia, czy zadana akcja została 
 * wykonana poprawnie. Badanie może zostać przeprowadzone dla dowolnej
 * liczby plików wejściowych, a dla każdego z plików może być 
 * przeprowadzone dowolną ilość razy.
 * Klasa daje użytkownikowi interfejs do wyboru plików wejściowych, 
 * źródłowych i liczby powtórzeń badania.
 * Po zakończeniu eksperymentu zbiorcze wyniki zostaną zapisane w pliku
 * o [nazwie](@ref wyjscie) ustalonej w kodzie programu. */
class Eksperyment {
public:
  /*!
   * @brief Konstruktor
   *
   * Konstruktor zrealizowany tak, by jego uruchomienie było jedynym
   * koniecznym wywołaniem w funkcji main.
   * @param[in] PlikWyj - nazwa pliku wyjściowego programu */
  Eksperyment(string PlikWyj);

  /*!
   * @brief Spis "zadań" do wykonania przez program 
   *
   * "Zadanie" jest zapisane jako struktura typu [Zrodlo](@ref Zrodlo),
   * z nazwami dwóch plików (wejściowego i wzorcowego) oraz liczbą
   * powtórzeń badania. */
  vector<Zrodlo> Tablica;

  /*!
   * @brief Spis wyników badań
   *
   * Wyniki zapisane są jako struktury typu [WynikBadania](@ref WynikBadania)
   * zawierającej: ilość badanych liczb, ilość badań oraz średni czas */
  vector<WynikBadania> Wyniki;

  /*!
   * @brief Nazwa pliku wyjściowego
   *
   * W pliku o tej nazwie zapisane zostaną zbiorczo informacje o badaniu,
   * tak jak w wektorze [Wyniki](@ref Wyniki) */
  string NazwaWyjscia;

private:

}; 

#endif

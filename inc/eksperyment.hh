/*! @file eksperyment.hh
 * @brief Deklaracja klasy Eksperyment, głównej w programie */

#ifndef EKSPERYMENT_HH
#define EKSPERYMENT_HH

#include <string>
#include <vector>

#include "tabliczb.hh"
#include "wynikbadania.hh"
#include "zrodlo.hh"

using namespace std;

/*!
 * @brief Sprawdza możliwość otwarcia pliku
 *
 * Przy stwierdzeniu niemożliwości pokazuje na cerr komunikat
 *
 * \retval true - plik daje się otworzyć
 * \retval false - pliku nie da się otworzyć */
bool SprawdzNazwe(string nazwa);

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
   * @brief Wczytanie danych z plików
   *
   * Funkcja sczytuje dane z plików do tablic Wejscie i Wzor. To, które
   * pliki wczytać, jest zdeterminowane liczbą podaną jako argument - 
   * ma ona odpowiadać pewnemu elementowi tablicy Zadania.
   *
   * @param[in] nr - indeks wektora Zadania, któremu mają odpowiadać
   * wczytywane pliki
   * @retval true - wczytywanie zakończone sukcesem
   * @retval false - błąd odczytu */
  bool WczytajPliki (unsigned nr);

  /*!
   * @brief Spis "zadań" do wykonania przez program 
   *
   * "Zadanie" jest zapisane jako struktura typu [Zrodlo](@ref Zrodlo),
   * z nazwami dwóch plików (wejściowego i wzorcowego) oraz liczbą
   * powtórzeń badania. */
  vector<Zrodlo> Zadania;

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
  /*!
   * @brief Przetwarzane liczby
   *
   * Tablica na liczby, które program ma przetworzyć. */
  TabLiczb Wejscie;

  /*!
   * @brief Liczby wzorcowe
   *
   * Tablica na liczby, które zostaną porównane ze wzorcowymi. */
  TabLiczb Wzor;

  /*!
   * @brief Tworzy listę zadań
   *
   * Pyta użytkownika o ilość badań oraz nazwy plików wejściowych oraz
   * zapisuje uzyskane dane. Sprawdza możliwość otwarcia plików o nazwach
   * podanych przez użytkownika. 
   * @retval true - poprawne dzialanie
   * @retval false - wprowadzono jakąś niewłaściwą wartość */
  bool SpiszZadania();

  /*!
   * @brief Zapisuje do tablicy dane z jednego pliku
   *
   * Plik musi być zgodny ze schematem z opisu struktury [Zrodlo](@ref Zrodlo)
   * @param[in] nazwa - nazwa pliku
   * @param[out] tab - tablica do której są wczytane dane 
   * @retval true - wczytanie zakończone sukcesem
   * @retval false - błąd we wczytaniu pliku (nie-liczba) lub niezgodność
   * ze schematem */
  bool WczytajJedenPlik(string nazwa, TabLiczb& tab);

  /*!
   * @brief Dokonuje wielokrotnego pomiaru
   *
   * Funkcja dokonuje wielokrotnego wywołania funkcji Wejscie.RazyDwa()
   * i mierzy czas jej wykonania. Następnie zostaje dokonane porównanie
   * wyniku z tablicą Wzor. Ilość pomiarów jest brana z pola IleRazy
   * odpowiedniego elementu Zadania.
   *
   * @param[in] nr - numer indeksu w polu Zadania, z którego wzięta 
   * zostanie liczba pomiarów
   * @retval -1.0 - dla niezgodności ze wzorcem 
   * @return średni czas pomiaru. */
  float WielokrotnyPomiar(unsigned nr);
};

#endif

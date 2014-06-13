/*! @file eksperyment.hh
 * @brief Deklaracja klasy Eksperyment, głównej w programie */

#ifndef EKSPERYMENT_HH
#define EKSPERYMENT_HH

#include <string>
#include <vector>

#include "wynikbadania.hh"
#include "zrodlo.hh"
#include "graf.hh"
#include "punkt.hh"

using namespace std;

typedef Graf<Punkt, double> BadObiekt;

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
   *
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

  /*!
   * \brief Badany graf
   */
  Graf<Punkt, double> Mapa;

private:

  /*!
   * @brief Tworzy listę zadań
   *
   * Pyta użytkownika o ilość badań oraz nazwy plików wejściowych oraz
   * zapisuje uzyskane dane. Sprawdza możliwość otwarcia plików o nazwach
   * podanych przez użytkownika.  */
  void SpiszZadania();

  /*!
   * @brief Zapisuje wyniki w pliku CSV
   *
   * Funkcja tworzy plik o zadanej w polu NazwaWyjscia nazwie i zapisuje\
   * w nim dane z pola Wyniki rozdzielone przecinkami. Pierwszy wiersz
   * zajmują nazwy kolumn. */
  void Zapisz();

  /*!
   * \brief Wykonuje niezbędne działania wstępne
   *
   * Dokonuje wszystkich niezbędnych części eksperymentu, które znajdują
   * się w czasie pomiędzy wczytaniem plików z wejściowymi informacjami,
   * a działaniami, których czas mierzymy.
   * Przykładem jest np. wypełnienia kontenera danych, którego efektywność
   * (pod względem dostępu do danych) chcemy zmierzyć.
   *
   * \return Wskaźnik na nowoutworzony i przygotowany do dalszej części
   * eksperymentu obiekt */
  BadObiekt* Przygotuj();

  /*!
   * Struktura łączy dwie informacje z badania: średni czas wykonania
   * oraz koszt znaleznionej trasy.
   */
  struct Wynik {
	  float sr_czas;
	  double koszt;
  };
};

#endif

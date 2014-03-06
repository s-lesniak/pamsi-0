/*! @file tabliczb.hh
 * @brief Deklaracja klasy opisującej tablicę liczb */

#ifndef TABLICZB_HH
#define TABLICZB_HH

#include <vector>

using namespace std;

/*!
 * @brief Przechowuje liczby całkowite
 *
 * Klasa, dziedzicząca po std::vector, przechowuje dowolną ilość liczb
 * całkowitych. Jest obudowana odpowiednim interfejsem. */
class TabLiczb: public vector<int> {
public:
  /*!
   * @brief Porównuje dwie tablice liczb
   *
   * Sprawdza, czy dwie tablice mają tę samą długość oraz czy odpowiadające
   * sobie wzajemnie ich elementy są sobie równe
   *
   * @param[in] druga - tablica, z którą dokonane zostanie porównanie
   * @retval true - gdy wszystkie odpowiadające sobie pary liczb są sobie
   * równe
   * @retval false - gdy tablice są różnych długości lub przynajmniej 
   * jedna z odpowiadających sobie par jest nierówna */
  bool operator == (const TabLiczb& druga);

  /*!
   * @brief Podwajanie elementów
   *
   * Mnoży każdy z elementów tablicy razy dwa. */
  void RazyDwa();

  /*!
   * @brief Zamienia dwa elementy tablicy 
   * 
   * @param[in] i, j - indeksy zamienianych elementów liczone od zera.
   * Ich kolejność nie gra roli.
   * @retval true - prawidłowe wykonanie funkcji
   * @retval false - błąd wywołania indeks poza zasięgiem */
  bool ZamienElementy(unsigned i, unsigned j);
  
  /*!
   * @brief Odwraca kolejność wszystkich elementów tablicy
   *
   * Zmienia tablicę tak, by wyglądał jakby czytany od końca */
  void OdwrocKolejnosc();

  /*!
   * @brief Dodaje nowy element na koniec tablicy
   *
   * @param[in] elem - element do dodania */
  void DodajElement (int elem) { push_back(elem); }

  /*!
   * @brief Łączy z drugą tablicą
   *
   * W wynikowej tablicy będą najpierw elementy pierwszej, potem
   * drugiej (podanej za argument) tablicy.
   *
   * @param[in] zrodlo - tablca, z której dodane zostaną dane 
   * @return referencja do połączonej tablicy */
  TabLiczb& operator + (const TabLiczb& zrodlo);

  /*!
   * @brief Przypisuje jedną tablicę drugiej
   *
   * Wielkość wektora "roboczego" zostanie zmieniona, by dostosować
   * do wektora źródłowego, następnie element po elemencie zostanie
   * dokonane przepisanie danych.
   *
   * @param[in] zrodlo - wektor, z którego dokonana zostanie kopia */
  TabLiczb& operator = (const TabLiczb& zrodlo);

private:
  /*!
   * @brief Odwraca kolejność wybranych elementów tablicy
   *
   * @param[in] i, j - skrajne indeksy odwracanego fragmentu tablicy
   * @retval true - prawidłowe wywołanie funkcji
   * @retval false - błąd wywołania (indeks poza zasięgiem, zła ich
   * kolejność) */
  bool OdwrocKolejnosc(unsigned i, unsigned j);
}; 

/*!
 * @brief Łączy dwie tablice
 *
 * W wynikowej tablicy będą najpierw elementy pierwszej, potem
 * drugiej (podanej za argument) tablicy.
 *
 * @param[in, out] zrodlo1 - tablica, do której dodane zostaną 
 * elementy
 * @param[in] zrodlo2 - tablica bedaca zrodlem nowych danych */
void DodajElementy (TabLiczb& zrodlo1, const TabLiczb& zrodlo2);
#endif

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
}; 

#endif

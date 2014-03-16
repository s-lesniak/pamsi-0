/*! @file koltab.hh
 * @brief Deklaracja klasy implementującej kolejkę */

#ifndef KOLTAB_HH
#define KOLTAB_HH

using namespace std;

/*!
 * @brief Kolejka zaimplementowana tablicą
 *
 * Klasa realizuje strukturę "first in first out" (FIFO) liczb 
 * całkowitych za pomocą tablicy. */
class KolTab {
public:

  /*!
   * @brief Inicjalizacja pustej kolejki */
  KolTab(): Tablica(NULL), Rozmiar(0), Ilosc(0), Roznica(0) {}

  /*!
   * @brief Kładzie liczbę na kolejkę
   * @param[in] i - liczba do położenia na kolejkę */
  void push(int i);

  /*!
   * @brief Zdejmuje liczbę z początku kolejki
   * @return wartość zdjętego elementu */
  int pop();

  /*!
   * @brief Informuje użytkownika o zajętości kolejki 
   * @retval true - dla pustej kolejki (braku elementów)
   * @retval false - dla niepustej kolejki */
  bool is_empty() { return !(Ilosc); }

  /*!
   * @brief Zwraca ilość elementów w kolejce */
  unsigned size() { return Ilosc; }

  /*!
   * @brief Oblicza wskaźnik do pierwszego elementu właściwej kolejki
   *
   * Funkcja uwzględnia fakt, że pierwsze wartości tablicy mogą nie być
   * wartościami będącymi w kolejce i z użyciem pola [Ilosc](@ref Ilosc)
   * znajduje początek "użytecznej" części tablicy
   *
   * @return wskaźnik do elementu tablicy, który jest pierwszą pozycją w
   * kolejce */
  int* Poczatek() { return Tablica + Roznica; }

private:
  /*!
   * @brief Wskaźnik na wolną pamięć, w której są dane
   *
   * Wskaźnik niekoniecznie wskazuje na sensowne dane. Dzieje się tak,
   * ponieważ z kolejki są zdejmowane dane. Przy zdejmowaniu natomiast
   * nie zawsze jest dokonywana realokacja danych - zamiast tego 
   * pewną ilość początkowych komórek tablicy należy zignorować jako 
   * wartości śmieciowe. O tym, jaka to ilość, mówi [pole] (@ref Roznica)
   */
  int* Tablica;

  /*!
   * @brief Rozmiar kolejki */
  unsigned Rozmiar;

  /*!
   * @brief Ilość elementów w kolejce */
  unsigned Ilosc;

  /*!
   * @brief Ilość śmieciowych wartości w tablicy
   *
   * Pokazuje, ile początkowych komórek tablicy zajmują wartości, które
   * już nie są w kolejce i jako takie są śmieciowe. W ten sposób 
   * wyrażenie Tablica[Roznica] będzie oznaczało pierwszy element w
   * kolejce */
  unsigned Roznica;
}; 

#endif

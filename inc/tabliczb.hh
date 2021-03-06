/*! @file tabliczb.hh
 * @brief Deklaracja klasy opisującej tablicę liczb */

#ifndef TABLICZB_HH
#define TABLICZB_HH

#include <vector>
#include <cstdlib>

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
   * Sprawdza, czy dwie tablice mają tę samą długość oraz czy 
   * odpowiadające sobie wzajemnie ich elementy są sobie równe
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

  /*!
   * @brief Sortuje rosnąco tablicę algorytmem scalania */
  void MergeSort();

  /*!
   * @brief Sortuje rosnąco całą tablicę algorytmem quicksort 
   *
   * Funkcja pozwala na wybranie (poprzez parametr), czy sortować ze
   * stałym, czy losowym elementem pivot
   *
   * @param[in] optym - określa, czy korzystać z optymalizacji w
   * sortowaniu */
  void QuickSort(bool optym);

  /*!
   * @brief Sortuje rosnąco tablicę algorytmem kopcowym */
  //void HeapSort();

private:
  /*!
   * @brief Sortuje rosnąco fragment tablicy algorytmem quicksort 
   *
   * Funkcja pozwala na wybranie (poprzez parametr), czy sortować ze
   * stałym, czy losowym elementem pivot
   *
   * @param[in] optym - określa, czy korzystać z optymalizacji w
   * sortowaniu
   * @param[in] pocz, kon - krańcowe indeksy sortowanego fragmentu
   * tablicy. Ich kolejność jest istotna. (pocz <= kon) */
  void QuickSort(unsigned pocz, unsigned kon, bool optym = true);
 
  /*!
   * @brief Losuje parametr pivot sortowania
   *
   * Losuje liczbę z zadanego parametrami zakresu. Otrzymany wynik
   * ma w zamierzeniu być użyty jako element środkowy (pivot) sortowania
   * algorytmem quicksort
   *
   * @param[in] pocz, kon - krańcowe indeksy sortowanego fragmentu. Ich
   * kolejność jest istotna.
   * @return losowa liczba z podanego zakresu */
  unsigned LosujPivot (unsigned pocz, unsigned kon)
  { srand(time(NULL)); return (pocz + rand() % (kon - pocz + 1)); }

  /*!
   * @brief Odwraca kolejność wybranych elementów tablicy
   *
   * @param[in] i, j - skrajne indeksy odwracanego fragmentu tablicy
   * @retval true - prawidłowe wywołanie funkcji
   * @retval false - błąd wywołania (indeks poza zasięgiem, zła ich
   * kolejność) */
  bool OdwrocKolejnosc(unsigned i, unsigned j);

  /*!
   * @brief Dzieli tablicę na dwie możliwie różne części
   *
   * Usuwa zawartość zadanych w parametrze tablic. Do pierwszej z nich
   * kopiuje około połowę pierwszych elementów tablicy, a do drugiej -
   * pozostałe z nich.
   * W przypadku tablicy o nieparzystym rozmiarze podział zostanie
   * dokonany, tak, że druga tablica będzie większa o jeden.
   *
   * @param[out] pierwsza, druga - tablice, w których znajdą się 
   * połówki tablicy wyjściowej */
  void Podziel(TabLiczb &pierwsza, TabLiczb &druga);

  /*!
   * @brief Zamienia dwa elementy o zadanych indeksach
   *
   * Nie jest sprawdzana sensowność indeksów; ich kolejność nie gra
   * roli.
   * @param i, j - indeksy elementów do zamienienia */
  void Zamien (unsigned i, unsigned j)
  { int tmp = (*this)[i]; (*this)[i] = (*this)[j]; (*this)[j] = tmp; }
  
  /*!
   * @brief Tworzy z tablicy kopiec binarny
   *
   * Kopiec zostanie utworzony w taki sposób, że na jego szczycie
   * znajdzie się największa liczba */
  //void ZrobKopiec();

  /*!
   * @brief Uaktualnia strukturę tabeli jako kopca
   *
   * Modyfikuje ustawienie elementów tabeli tak, by spełniały one, w
   * danym zakresie, definicję kopca.
   * @param[in] i, j - granice indeksów, w których ma dochodzić do 
   * korekcji */
  //void PoprawKopiec (unsigned i, unsigned j);
}; 

/*!
 * @brief Łączy posortowane tablice w posortowaną tablicę
 *
 * Funkcja "wplata" elementy drugiej tablicy w pierwszą tak, by
 * utworzyć posortowaną (malejąco) całość.
 * Działanie funkcji zastosowanej do nieposortowanych tablic jest
 * nieokreślone.
 *
 * @param[in] pierwsza, druga - tablice źródłowe
 * @return scalona tablica */
TabLiczb ZlaczSort(const TabLiczb &pierwsza, const TabLiczb &druga);

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

/*!
 * @brief Wypisuje na strumień zawartość tablicy */
ostream& operator << (ostream &str, const TabLiczb &tab);
#endif

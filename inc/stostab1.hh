/*! @file stostabl1.hh
 * @brief Deklaracja klasy implementującej stos wer. 1 */

#ifndef STOSTAB1_HH
#define STOSTAB1_HH

using namespace std;

/*!
 * @brief Stos zaimplementowany tablicą
 *
 * Stos działa tak, że z każdym nowym elementem dokonywana jest
 * realokacja pamięci o jeden. Obudowana typowymi dla stosu operacjami */
class StosTab1 {
public:

  /*!
   * @brief Kładzie liczbę na stos
   *
   * Zwiększa rozmiar tablicy o jeden, a na wolnym elemencie kładzie
   * nową liczbę */
  void push(int i);

  /*!
   * @brief Zdejmuje liczbę z wierzchu stosu
   * @return wartość zdjętego elementu */
  int pop();

  /*!
   * @brief Informuje użytkownika o zajętości stosu 
   * @retval true - dla pustego stosu (braku elementów)
   * @retval false - dla niepustego stosu */
  bool is_empty();

  /*!
   * @brief Zwraca ilość elementów na stosie */
  unsigned size();

private:

};

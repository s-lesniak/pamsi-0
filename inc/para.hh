/*! @file para.hh
 * @brief Deklaracja struktury implementującej parę elementów tablicy
 * asocjacyjnej */

#ifndef PARA_HH
#define PARA_HH

/*!
 * @brief Pojedynczy element tablicy asocjacyjnej
 *
 * Szablon struktury łączy dane dwóch typów, z czego pierwszy z nich 
 * jest stały (klucza i wartości). 
 *
 * @tparam TypKlucza - typ danych, jakiego będą klucze. Musi mieć
 * zrealizowany operator >
 * @tparam TypWartosci - typ danych, jakiego będą wartości. */
template <class TypKlucza, class TypWartosci>
struct Para{

};

#endif

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

using namespace std;

/** Implementacja ulamka:
Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
          Settery nie powinny skracac ulamkow
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

class Fraction
{
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler

#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
// TODO: zaimplementowac cialo klasy, usunac ten komentarz i warning powyzszy
    int numerator{};
    int denominator{};

public:

    Fraction(int = 0, int = 1);
    void setNumerator(int);
    void setDenominator(int);
    int getNumerator() const;
    int getDenominator() const;
    Fraction operator+ (const Fraction &firstFraction) const;
    Fraction operator* (const Fraction &firstFraction) const;
    static Fraction skroc(Fraction &fraction);
};

#endif // FRACTION_H

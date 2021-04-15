#include "fraction.h"
#include <iostream>

using namespace std;

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
// TODO: zaimplementowac metody klasy, usunac ten komentarz i warning powyzszy


void Fraction::setNumerator(int licznik) {
    numerator = licznik;
}

void Fraction::setDenominator(int mianownik) {
    if (mianownik == 0){
        throw invalid_argument("Mianownik nie moze byc rowny 0");
    }
    denominator = mianownik;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {

    return denominator;
}



Fraction Fraction::operator+(const Fraction &firstFraction) const {
    Fraction result;

    result.setNumerator(getDenominator() * firstFraction.getNumerator() + firstFraction.getDenominator() * getNumerator());
    result.setDenominator(firstFraction.getDenominator() * getDenominator());
    skroc(result);

    return result;
}

Fraction Fraction::operator*(const Fraction &firstFraction) const {
    Fraction result;

    result.setNumerator(getNumerator() * firstFraction.getNumerator());
    result.setDenominator(getDenominator() * firstFraction.getDenominator());
    skroc(result);

    return result;
}

Fraction Fraction::skroc(Fraction &fraction) {

    int a = fraction.getNumerator();
    int b = fraction.getDenominator();

    if( a != b ) {

        do {
            if( a > b ) {
                a = a - b;
            }
            if( a < b ) {
                b = b - a;
            };
        }
        while( a != b );

    }

    fraction.setNumerator(fraction.getNumerator() / a);
    fraction.setDenominator(fraction.getDenominator() / b);
    return fraction;
}

Fraction::Fraction(int licznik, int mianownik) {

    numerator = licznik;
    denominator = mianownik;

}


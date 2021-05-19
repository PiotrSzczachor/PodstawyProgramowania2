//
// Created by piotr on 18.05.2021.
//

#ifndef ZAJECIA11_VECTOREDLIST_H
#define ZAJECIA11_VECTOREDLIST_H

/*
Zadanie do zrobienia, trudne ale cenne doświadczenie w dalszej karierze programisty (nie tylko C++), zainspirowane zadaniem z kiedyś.

Państwa zadaniem jest zrobienie klasy VectoredList, która będzie formą pośrednią między Vectorem i Listą.
Pośredniość będzie polegać na tym, że mamy bloki pamięci po N elementów, z których każdy blok wskazuje na następny i poprzedni blok.
 Rozmiar bloku powinien być ustawiony stałą czasu kompilacji N na wartość 10.
Klasa VectoredList musi zawierać wskaźniki na składowe: head, tail, size_ (ilość bloków), capacity_ (ile się zmieści do aktualnie posiadanych bloków).
 Poza tą klasą proszę o zaimplementowanie klasy wewnętrznej:
 Bucket, która będzie posiadała wskaźniki na poprzedni i następny element, oraz informacje o ilości elementów, a także ww. N.
 Typem agregowanym powinien być std::string.
Proszę pamiętać o zwalnianiu pamięci, odpowiednich ustawieniach w konstruktorze. Można dodać dodatkowe metody, przydane w użyciu.
Powinny być następujące metody:

push_back wrzucająca element na koniec wszystkich elementów, w razie czego powinno allokować nowy kubełek.
operator[] zwracający referencje do elementu o danym indeksie z odpowiedniego kubełka:
TESTY: Proszę tak dodać 101 elementów i przejść od odwrotnej strony po elementach. [1p za operator[] i push_back]

Proszę o zaimplementowanie iteratora, będącego klasą wewnątrzną, który by umożliwiał przeglądanie elementów (metody: !=, operator*, operator++).
Oraz proszę pamiętać o metodach begin() i end() zwracających iterator.
TEST: VectoredList v(...);  // [1p]
for (auto& element : v)
cout << v << endl;
erase - metoda, która przyjmuje iterator i usuwa wskazany element, przesuwając kolejne elementy o jedną pozycje w lewo
erase, która przyjmuje parę iteratorów i usuwa cały zakres
TEST: dodać 22 elementów, usunąć trzeci i wyświetlić [1p]
operator=, który będzie kopiował głęboko.
TEST: VectoredList v(...);
{
VectoredList v2(...);
v = v2;
}
// teraz wyświetlić v, oraz po zakończeniu programu nic nie powinno się wywalić // [1p]
*/

#include <string>
#include <array>
#include <iostream>

using namespace std;


const int N = 10;

class VectorList {
public:
    class Iterator;
    class Bucket{
    public:
        VectorList* next;
        VectorList* previous;
        string* data;
        Bucket();
        ~Bucket();
    };

    Bucket* head;
    Bucket* tail;
    int size;
    int capacity;
    VectorList();
    void pushback(string element);
    void increaseCapacity();
    void printVectoredList() const;
    void printReversedVectorList() const;

    string& operator[](int elementNumber) const {
        return head[elementNumber/N].data[elementNumber%N];
    }

    void erase(int index);
    void erase(int from, int to);

    class Iterator {
    public:
        string* pointer;
        explicit Iterator(string* bucket_element);
        Iterator begin();
        Iterator end();

    };
    VectorList& operator=(VectorList object){
        if (this != &object)
        {
            delete[] head;
            head = object.head;
        }
        return *this;

    }
};


#endif //ZAJECIA11_VECTOREDLIST_H

#include <iostream>
#include "pprintpp-master/include/pprintpp/pprintpp.hpp"

using namespace std;

struct ulamek
{
    int licznik;
    int mianownik;
};


void print(int number)
{
    pprintf("{}", number);
}

void print(float number)
{
    pprintf("{}", number);
}

void print(struct ulamek ulamek)
{
    pprintf("{}/{}", ulamek.licznik, ulamek.mianownik);
}

void print(...)
{
    pprintf("Nie mozna wyswietlic argumentu");
}

void print(string* pointer)
{
    pprintf("{}", pointer);
}

void print(int* arr, int arr_count)
{
    for(int i=0; i<arr_count; i++)
    {
        pprintf("{}", arr[i]);
    }
}

void print(ulamek &ref)
{
    pprintf("{}/{}", ref.licznik, ref.mianownik);
}


int main()
{

}
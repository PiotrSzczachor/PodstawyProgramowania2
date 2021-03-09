#include <iostream>
#include "fmt-master/include/fmt/core.h"

using namespace std;

struct ulamek
{
    int licznik;
    int mianownik;
};


void print(int number)
{
    fmt::print("Hello, world!\n");
}

void print(float number)
{
    fmt::print("{}", number);
}

void print(struct ulamek ulamek)
{
    fmt::print("{}/{}", ulamek.licznik, ulamek.mianownik);
}

void print(...)
{
    fmt::print("Nie mozna wyswietlic argumentu\n");
}

void print(void* pointer)
{
    fmt::print("{}", pointer);
}

void print(int* arr, int arr_count)
{
    for(int i=0; i<arr_count; i++)
    {
        fmt::print("{}", arr[i]);
    }
}

void print(ulamek &ref)
{
    fmt::print("{}/{}", ref.licznik, ref.mianownik);
}


int main()
{

}
#include <iostream>
#include "VectoredList.h"

using namespace std;

int main() {
    VectorList a;
    VectorList b;
    cout<<"\n\n---------------------------------------\nTest 1(pushback, operator[]):\n\n";
    for(int i=0; i<101; i++) {
        if(i<50){
            a.pushback("Start ");
        }else{
            a.pushback("End  ");
        }
    }
    a.printVectoredList();
    //cout<<a.head[2].data[3];
    cout<<"\n\noperator[](23): \n";
    cout<<a.operator[](23);
    cout<<"\n\n";
    cout<<"Odwrocone elementy VectoredList: \n";
    a.printReversedVectorList();

    cout<<"\n\n---------------------------------------\nTest 2(erase pojedynczy element, erase zakres elementow): \n\n";

    VectorList c;
    VectorList d;

    c.pushback("word1  ");
    c.pushback("word2  ");
    c.pushback("word3  ");
    c.pushback("word4  ");
    c.pushback("word5  ");
    c.pushback("word6  ");
    c.pushback("word7  ");
    c.pushback("word8  ");
    c.pushback("word9  ");
    c.pushback("word10  ");
    c.pushback("word11  ");
    c.pushback("word12  ");
    c.pushback("word13  ");
    c.pushback("word14  ");
    c.pushback("word15  ");
    c.pushback("word16  ");
    c.pushback("word17  ");
    c.pushback("word18  ");
    c.pushback("word19  ");
    c.pushback("word20  ");
    c.pushback("word21  ");
    c.pushback("word22  ");

    cout<<"\nPrzed usunieciem: \n";
    c.printVectoredList();
    cout<<"\n\nPo usunieciu 3 elementu: \n";
    c.erase(3);
    c.printVectoredList();
    cout<<"\n\nPo usunieciu elementow od 9 do 20: \n";
    c.erase(9,20);
    c.printVectoredList();
    cout<<"\n\n";


    cout<<"---------------------------------------\nTest 3 (operator= kopiujacy gleboko):\n\n";
    cout<<"Wektor d przed kopia (pusty):\n";
    d.printVectoredList();
    cout<<"\n\nWektor d po kopii z c: \n";
    d.operator=(c);
    d.printVectoredList();
    d.pushback("Dodany element");
    cout<<"\n\nWektor d po dodaniu elementu:\n";
    d.printVectoredList();
    cout<<"\n\nWektor c (Nie zmienia sie po dodaniu elementu do jego kopii(d)):\n";
    c.printVectoredList();


    return 0;
}

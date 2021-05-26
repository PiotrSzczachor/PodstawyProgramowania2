#include <iostream>
#include "VectoredList.h"
#include "vector"
using namespace std;

int main() {
    /*
    for (int i = 0; i < 101; ++i)
        v.push_back(to_string(i));

    for (int i = 0; i < 101; ++i)
    {
        cout<< v[100-i]<<" ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 4 ]" << endl;
    VectoredList v2;
    v2.push_back(to_string(2));
    cout << "Size before using = "<<v2.get_size() << endl;
    v2 = v;
    for (int i = 0; i <= v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "\n[ TEST begin() i end(), ++, *]" << endl;
    VectoredList::VectoredListIterator it(v2);
    cout << it.get() <<endl;
    ++it;
    cout << it.get() <<endl;
    VectoredList::VectoredListIterator it2(v2,15);
    cout << it2.get() <<endl;
    cout<< "*it2: "<< *it2 << endl;
    cout<< "v2 begin(): "<< v2.begin().get() << endl;
    cout<< "v2 end(): "<< v2.end().get() << endl;
    cout<< "return index it2: "<< it2.return_index(v2) << endl;
    cout << endl << "[TEST ZAKRESOWE FOR]" << endl;;
    for (const auto& element : v2)
    {
        cout << element << endl;
    }

    cout << endl << "[ TEST 3 erase ]" << endl;
    //doadanie 22 elementow
    for(int i =0; i < 22; ++i)
    {
        v2.push_back(to_string(22+i));
    }
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    //usuwanie 3-ego elementu
    VectoredList::VectoredListIterator it3(v2,3);
    v2.erase(it3);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl << "[ TEST 3 erase(it1,it2) ]" << endl;
    cout <<"Size before erasing: " <<v2.get_size() << endl;
    VectoredList::VectoredListIterator it4(v2,3);
    VectoredList::VectoredListIterator it5(v2,13);
    v2.erase(it4,it5);
    cout <<"Size after erasing: " <<v2.get_size() << endl;
    for (int i = 0; i < v2.get_size(); ++i)
    {
        cout << v2[i] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl << "[ TEST 5 erase(it1,it2) ]" << endl;
    VectoredList v3;
    for (int i = 0; i < 103; ++i)
        v3.push_back(to_string(i));
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    }
    cout << endl;
    VectoredList::VectoredListIterator it6(v3,87);
    VectoredList::VectoredListIterator it7(v3,100);
    v3.erase(it6,it7);
    cout<< "AFTER: "<< endl;
    for (int i = 0; i < v3.get_size(); ++i)
    {
        cout << v3[i] << " ";
        if (i % 10 == 9)
            cout << endl;
    } */

    cout << endl << "[ TEST 1 ]" << endl;
    vector<VectoredList> vec;
    vec.push_back(VectoredList{});
    cout<<"\n\n [ TEST 2 ]\n";
    VectoredList v1;
    VectoredList v2;
    for (int i = 0; i < 101; ++i)
        v1.push_back(to_string(i));
    for (int i = 101; i < 201; ++i)
        v2.push_back(to_string(i));
    v1.operator+(v2);
    for (int i=0; i<150; i++)
        cout<<v1[i]<<" ";
    vector<string> vec2;
    vec2.push_back("word1");
    vec2.push_back("word2");
    vec2.push_back("word3");
    vec2.push_back("word4");
    vec2.push_back("word5");
    vec2.push_back("word6");
    VectoredList test;
    test.assign(vec2);
    cout<<"\n\n[ TEST 3 ]\n";
    for(int i=0; i<test.size;i++) {
        cout<<test[i]<<endl;
    }


    return 0;
}
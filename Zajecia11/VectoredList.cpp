//
// Created by piotr on 18.05.2021.
//

#include "VectoredList.h"

#include <utility>
//------------------------------------------------------------
// Bucket Konstruktor
VectorList::Bucket::Bucket() {
    next = nullptr;
    previous = nullptr;
    data = new string[N];
}
//-------------------------------------------------------------
// Bucket Destruktor
VectorList::Bucket::~Bucket() {
    delete[] data;
    next = previous = nullptr;
}
//-------------------------------------------------------------
// VectorList Konstruktor
VectorList::VectorList() {
    head = new Bucket[1];
    tail = head;
    head->previous = nullptr;
    size = 0;
    capacity = N;
}
//-------------------------------------------------------------
//Metoda pushback
void VectorList::pushback(string element) {
    goBack:
    int capacity_counter = 0;
    int bucket_counter = 0;
    int element_counter = 0;
    while (!head[bucket_counter].data[element_counter].empty() && element_counter < N) {
        element_counter++;
        capacity_counter++;
        if(capacity_counter == capacity)
        {
            increaseCapacity();
            goto goBack;
        }
        if (element_counter == N) {
            element_counter = 0;
            bucket_counter++;
        }
    }
    head[bucket_counter].data[element_counter] = element;
}
//-------------------------------------------------------------
//Zwiększanie capacity
void VectorList::increaseCapacity() {
   int newCapacity = capacity*2;
   auto * tmp = new Bucket[newCapacity];
   for(int i=0; i<capacity/N; i++){
       for(int j=0; j<N; j++){
           tmp[i].data[j] = head[i].data[j];
       }
   }
   head = tmp;
   capacity = newCapacity;
}
//-------------------------------------------------------------
//Wyswietlanie zawartosci
void VectorList::printVectoredList() const {
    int i = 0;
    int j = 0;
    while(!head[i].data[j].empty()) {
        cout<<head[i].data[j];
        j++;
        if(j == N) {
            j = 0;
            i++;
        }
    }
}
//-------------------------------------------------------------
//Wyswietlanie od konca
void VectorList::printReversedVectorList() const {
    int elements_counter = 0;
    int i = 0;
    int j = 0;
    while(!head[i].data[j].empty()) {
        //cout<<head[i].data[j];
        j++;
        elements_counter++;
        if(j == N) {
            j = 0;
            i++;
        }
    }
    for(int index=elements_counter; index>0; index--) {
        cout<<head[index/N].data[index%N];
    }
}
//-------------------------------------------------------------
//Usuwanie elementu
void VectorList::erase(int index) {
    index = index - 1;
    int old_bucket_counter = 0;
    int new_bucket_counter = 0;
    int old_data_counter = 0;
    int new_data_counter = 0;
    int newCapacity = capacity - 1;
    auto * tmp = new Bucket[newCapacity];
    while(!head[old_bucket_counter].data[old_data_counter].empty()) {
        if(old_bucket_counter==index/N && old_data_counter==index%N) {
            old_data_counter++;
        }
        tmp[new_bucket_counter].data[new_data_counter] = head[old_bucket_counter].data[old_data_counter];
        new_data_counter++;
        old_data_counter++;
        if(old_data_counter == N) {
            old_data_counter = 0;
            old_bucket_counter++;
        }
        if(new_data_counter == N) {
            new_data_counter = 0;
            new_bucket_counter++;
        }
    }
    head = tmp;
    capacity = newCapacity;
}
//--------------------------------------------------------------
//Usuwanie przedzialu elementow
void VectorList::erase(int from, int to) {
    int index = from - 1;
    int old_bucket_counter = 0;
    int new_bucket_counter = 0;
    int old_data_counter = 0;
    int new_data_counter = 0;
    int newCapacity = capacity - (to-from);
    auto * tmp = new Bucket[newCapacity];
    while(!head[old_bucket_counter].data[old_data_counter].empty()) {
        if(old_bucket_counter==index/N && old_data_counter==index%N) {
            old_data_counter = to%N;
            old_bucket_counter = to/N;
        }
        tmp[new_bucket_counter].data[new_data_counter] = head[old_bucket_counter].data[old_data_counter];
        new_data_counter++;
        old_data_counter++;
        if(old_data_counter == N) {
            old_data_counter = 0;
            old_bucket_counter++;
        }
        if(new_data_counter == N) {
            new_data_counter = 0;
            new_bucket_counter++;
        }
    }
    head = tmp;
    capacity = newCapacity;

}




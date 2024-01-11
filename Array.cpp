//
// Created by PC on 7/15/2023.
//

#include "Array.h"
#include <iostream>
using namespace std;

Array::Array(int size) {
    values = new int[size];
    this->size = size;


}

Array::~Array() {
    delete[] values;
}

void Array::print() {
    for (int i = 0; i < count; i++) {
        cout << values[i] << '\t';
    }
}

void Array::insert(int item) {
    if (count >= size) {
        size *= 2;
        auto new_values = new int[size];
        for (int i = 0; i < size/2; i++) {
            new_values[i] = values[i];
        }
        values = new_values;
    }
    values[count++] = item;

}

void Array::remove_at(int index) {
    values[index] = 0;
    for (int i = index; i < count; i++) {
        values[i] = values[i + 1];
    }
    count--;
}


int Array::index_of(int num) {
    for (int i = 0; i < count; i++)
        if (values[i] == num) return i;
    return -1;
}

int Array::max() {
    int max = values[0];
    for (int i = 1; i < count; i++)
        if (values[i] > max)
            max = values[i];
    return max;
}

//int* Array::intersect(int* arr) {
//    int c = 0;
//    int* intesect =  new int;
//    int size = sizeof(arr) / sizeof(arr[0]);
//    for (int i = 0; i < size; i++) {
//        if (this->index_of(arr[i]) != -1){
//            intesect[c++] = arr[i];
//        }
//    }
//    return intesect;
//    delete[] intesect;
//}



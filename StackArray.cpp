//
// Created by PC on 7/17/2023.
//

#include "StackArray.h"
#include <iostream>
using namespace std;

StackArray::StackArray(int s) {
    size = s;
    values = new int[s];
}

void StackArray::push(int item) {
    if (count == size){
        size *= 2;
        auto new_values = new int[size];
        for (int i = 0; i < size / 2; i++)
            new_values[i] = values[i];
        values = new_values;
    }
    values[count++] = item;

}

int StackArray::pop() {
    int returned_item = values[count];
    values[count--] = 0;
    return returned_item;
}

int StackArray::peek() {
    return values[count];
}

bool StackArray::is_empty() {
    return count == 0;
}

void StackArray::display() {
    for (int i = 0; i < count; i++) {
        cout << values[i] << '\n';
    }

}



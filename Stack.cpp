//
// Created by PC on 7/16/2023.
//

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    top = nullptr;
}

void Stack::push(int value) {
    Node* new_node = new Node(value);
    if (is_empty()) {
        top = new_node;
    } else {
        new_node->next = top;
        top = new_node;

    }

}

bool Stack::is_empty() {
    return top == nullptr;
}

void Stack::display() {
    auto copy = top;
    while (copy != nullptr) {
        cout << copy->value << "\n";
        copy = copy->next;
    }

}

int Stack::pop() {
    int value = top->value;
    auto delptr = top;
    top = top->next;
    delete[] delptr;
    return value;
}

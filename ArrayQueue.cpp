//
// Created by PC on 7/17/2023.
//

#include "ArrayQueue.h"
#include <iostream>
using namespace std;
ArrayQueue::ArrayQueue(int s) {
    values = new int[s];
    size = s;
}

void ArrayQueue::enqueue(int item) {
    if (count == size) {
        cout << "\nSize full\n";
        return;
    }
    values[rear] = item;
    rear = (rear+1) % size;
    count++;

}

int ArrayQueue::dequeue() {
    auto item = values[front];
    values[front] = 0;
    front = (front + 1) % 5;
    count --;
    return item;

}

int ArrayQueue::peek() {
    return values[front];

}

bool ArrayQueue::is_empty() {
    return front == 0;
}

bool ArrayQueue::is_full() {
    return count == size;
}

void ArrayQueue::display() {
    for (int i = 0; i < size; i++) {
        cout << values[i] << '\n';
    }

}

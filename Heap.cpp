//
// Created by PC on 7/30/2023.
//

#include "Heap.h"
#include <iostream>

void Heap::swap_index(int first, int second) {
    int temp = heap[first];
    heap[first] = heap[second];
    heap[second] = temp;
}

void Heap::insert(int item) {
    if (isFull()) {
        std::cout << "Heap is full!!";
        return;
    }
    heap[count++] = item;
    bubbleUp();
}

void Heap::bubbleUp() {
    int index = count - 1;
    while (index > 0 && heap[index] > heap[parent(index)]) {
        swap_index(index, parent(index));
        index = parent(index);
    }
}

bool Heap::isFull() const {
    return size == count;
}

int Heap::remove() {
    if (isEmpty()) {
        std::cout << "Empty Heap!! cannot remove";
        return -1;
    }
    int item = heap[0];
    heap[0] = heap[--count];
    bubbleDown();
    return item;
}

void Heap::bubbleDown() {
    int index = 0;
    while (index < count) {
        int leftIndex = leftChildIndex(index);
        int rightIndex = rightChildIndex(index);
        int largerChildIndex = index;

        if (leftIndex < count && heap[leftIndex] > heap[largerChildIndex])
            largerChildIndex = leftIndex;

        if (rightIndex < count && heap[rightIndex] > heap[largerChildIndex])
            largerChildIndex = rightIndex;

        if (largerChildIndex == index)
            break;

        swap_index(index, largerChildIndex);
        index = largerChildIndex;
    }
}

bool Heap::isEmpty() const {
    return count == 0;
}

int Heap::parent(int index) {
    return (index - 1) / 2;
}

int Heap::leftChildIndex(int index) {
    return (index * 2 + 1);
}

int Heap::rightChildIndex(int index) {
    return (index * 2 + 2);
}

void Heap::print() {
    for (int i = 0; i < count; i++)
        std::cout << heap[i] << ' ';
    std::cout << '\n';
}


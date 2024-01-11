//
// Created by PC on 7/30/2023.
//

#include "Heap.h"

Heap::Heap(int s) {
    heap = new int[s];
    size = s;
}

void Heap::swap_index(int first, int second) {
    int temp = heap[first];
    heap[first] = heap[second];
    heap[second] = temp;
}

void Heap::insert(int item) {
    if (count == size) {
        return;
    }
    heap[count++] = item;
    int index = count -1;
    int parent_index = index - 1 / 2;
    while (heap[index], parent_index){
        swap_index(index, parent_index);
        index = index - 1 / 2;
    }


}

Heap::~Heap() {
    delete[] heap;
}

void Heap::remove(int item) {

}

void Heap::pubble_up() {

}

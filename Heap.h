//
// Created by PC on 7/30/2023.
//

#ifndef FOR_TRYING_HEAP_H
#define FOR_TRYING_HEAP_H

class Heap {
private:
    int size = 10;
    int *heap = new int[size];
    int count = 0;

    void swap_index(int first, int second);

    int parent(int index);

    int leftChildIndex(int index);

    int rightChildIndex(int index);

public:
    void bubbleUp();

    int remove();

    void insert(int item);

    bool isFull() const;

    void print();

    bool isEmpty() const;

    void bubbleDown();
};

// functions that uses a heap

void swap(int *arr, int first, int second) {
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void heapifyItem(int *arr, int index, int size) {
    int largerIndex = index;
    int leftChildIndex = index * 2 + 1;
    int rightChildIndex = index * 2 + 2;

    if (arr[largerIndex] < arr[leftChildIndex] && leftChildIndex < size)
        largerIndex = leftChildIndex;
    if (arr[largerIndex] < arr[rightChildIndex] && rightChildIndex < size)
        largerIndex = rightChildIndex;

    if (largerIndex == index)
        return;

    swap(arr, index, largerIndex);
    heapifyItem(arr, largerIndex, size);
}

void heapify(int *arr, int size) {
    int lastParentIndex = (size / 2) - 1;
    for (int i = lastParentIndex; i >= 0; i--)
        heapifyItem(arr, i, size);
}

int getKthLargest(int *arr, int size, int k) {
    Heap heap;
    for (int i = 0; i < size; i++)
        heap.insert(arr[i]);

    for (int i = 0; i < k-1; i++)
        heap.remove();

    return heap.remove();
}

#endif //FOR_TRYING_HEAP_H

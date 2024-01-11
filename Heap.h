//
// Created by PC on 7/30/2023.
//

#ifndef FOR_TRYING_HEAP_H
#define FOR_TRYING_HEAP_H


class Heap {
private:
    int* heap;
    int size = 10;
    int count = 0;

    void swap_index(int first, int second);

    void pubble_up();

public:
    Heap(int s);
    ~Heap();
    void remove(int item);

    void insert(int item);

};


#endif //FOR_TRYING_HEAP_H

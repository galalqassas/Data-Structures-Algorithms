//
// Created by PC on 7/17/2023.
//

#ifndef FOR_TRYING_ARRAYQUEUE_H
#define FOR_TRYING_ARRAYQUEUE_H

class ArrayQueue {
private:
    int size;
    int* values;
    int front = 0;
    int rear = 0;
    int count = 0;
public:
    ArrayQueue(int s);
    void enqueue(int item);
    int dequeue();
    int peek();
    bool is_empty();
    bool is_full();

    void display();
};


#endif //FOR_TRYING_ARRAYQUEUE_H

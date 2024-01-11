//
// Created by PC on 7/17/2023.
//

#ifndef FOR_TRYING_STACKARRAY_H
#define FOR_TRYING_STACKARRAY_H


class StackArray {
private:
    int* values;
    int size;
    int count = 0;
public:
    StackArray(int s);

    void push(int item);

    int pop();
    int peek();

    bool is_empty();

    void display();
};


#endif //FOR_TRYING_STACKARRAY_H

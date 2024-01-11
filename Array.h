//
// Created by PC on 7/15/2023.
//

#ifndef FOR_TRYING_ARRAY_H
#define FOR_TRYING_ARRAY_H


class Array {
private:
    int* values;
    int size;
    int count = 0;

public:
    Array(int size);
    ~Array();

    void print();

    void insert(int item);

    void remove_at(int index);

    int index_of(int num);
    int max();

//    int* intersect(int* arr);
};



#endif //FOR_TRYING_ARRAY_H

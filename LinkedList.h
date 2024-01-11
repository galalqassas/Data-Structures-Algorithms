// Created by Pc on 7/2/2023.

#ifndef FOR_TRYING_LINKEDLIST_H
#define FOR_TRYING_LINKEDLIST_H

#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node{
    public:
        int value;
        Node* next;
        Node(int value): value(value), next(nullptr){}
    };
    Node* head;
    Node* tail;
    bool isEmpty(){
        return (head == nullptr);
    }
    static int size;
public:
    static int getSize();

    static void setSize(int size);

public:
    LinkedList(){head = nullptr; tail = nullptr;}
    ~LinkedList();
    void add_first(int item);
    void add_last(int item);
    void display();

    void delete_first();
    void delete_last();

    bool contains(int item);
    int find(int key);
    int* to_array();

    void reverse();

    int get_kth_from_the_end(int k);
};

#endif //FOR_TRYING_LINKEDLIST_H
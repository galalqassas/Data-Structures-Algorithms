//
// Created by PC on 7/16/2023.
//

#ifndef FOR_TRYING_STACK_H
#define FOR_TRYING_STACK_H


class Stack {
private:
    class Node{
    public:
        int value;
        Node* next;
        Node(int value): value(value), next(nullptr){}
    };
    Node* top;
public:
    Stack();
    void push(int value);
    bool is_empty();
    void display();

    int pop();

};


#endif //FOR_TRYING_STACK_H

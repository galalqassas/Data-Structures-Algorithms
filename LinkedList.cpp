//
// Created by Pc on 7/2/2023.
//

#include "LinkedList.h"

int LinkedList::size = 0;

void LinkedList::display() {
    auto temp = head;
    while (temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void LinkedList::add_first(int item) {
    Node* n = new Node(item);
    if (isEmpty()) {
        head = n;
        tail = n;
    }
    else{
        n->next = head;
        head = n;
    }
    LinkedList::size ++;
}

void LinkedList::add_last(int item) {
    Node* n = new Node(item);
    if (isEmpty()){
        head = n;
        tail = n;
    }
    else{
        tail->next = n;
        tail = n;
    }
    LinkedList::size ++;
}

LinkedList::~LinkedList() {
    auto temp = head;
    while (temp != nullptr){
        auto next = temp->next;
        delete temp;
        temp = next;
    }
}

int LinkedList::find(int key) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->value == key) {
            return index;
        } else {
            index++;
            temp = temp->next;
        }
    }
    return -1;
}

void LinkedList::delete_first() {
    if (head == tail){
        head = tail = nullptr;
        LinkedList::size = 0;
        return;
    } else if (isEmpty()) {
        return;
    }else{
        Node *second = head->next;
        head->next = nullptr;
        head = second;
        LinkedList::size--;
    }
}

void LinkedList::delete_last() {
    if (head == tail) {
        head = tail = nullptr;
        LinkedList::size = 0;
        return;
    }else if (isEmpty()){
        return;
    } else {
        auto temp = head;
        while (true) {
            if (temp->next->next == nullptr) {
                auto before_last = temp;
                before_last->next = nullptr;
                tail = before_last;
                break;
            } else {
                temp = temp->next;
            }
        }
        LinkedList::size--;
    }
}

bool LinkedList::contains(int item) {
    return (find(item) != -1);
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::setSize(int size) {
    LinkedList::size = size;
}

int* LinkedList::to_array() {
    int* linked_list_array = new int[LinkedList::getSize()];
    auto temp = head;
    int index = 0;
    while (temp != nullptr) {
        linked_list_array[index++] = temp->value;
        temp = temp->next;
    }
    return linked_list_array;
}

// [10 -> 20 -> 30]

void LinkedList::reverse() {
    if (isEmpty()) return;
    auto previous = head;
    auto current = head->next;

    previous->next = nullptr;

    while (current != nullptr) {
        auto backup = current->next;
        current->next = previous;
        previous = current;
        current = backup;
    }
    tail = head;
    tail->next = nullptr;
    head=previous;
}

int LinkedList::get_kth_from_the_end(int k) {
    // check if k is valid
    if (k > LinkedList::size || k <= 0) return -1;

    // initialize two pointers to the head of the list
    auto first = head;
    auto kth = first;

    // move the first pointer k steps ahead of the second
    for (int i = 1; i < k; i++) {
        kth = kth->next;
    }

    // move both pointers until the second one reaches the end
    while (kth->next != nullptr) {
        first = first->next;
        kth=kth->next;
    }

    // return the value of the first pointer, which is the kth node from the end
    return first->value;
}


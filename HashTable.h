//
// Created by PC on 7/24/2023.
//

#ifndef FOR_TRYING_HASHTABLE_H
#define FOR_TRYING_HASHTABLE_H

#include <iostream>
using namespace std;
#include <forward_list>
class HashTable {
private:
    class Entry{
    public:
        int key;
        string value;
        Entry(int key, const string& value) : key(key), value(value) {};
    };
    int size = 5;
    forward_list<Entry>* entries = new forward_list<Entry>[size];

    int hash(int key){
        return (key % size);
    }
public:
    virtual ~HashTable();
    void put(int key, string& value);

    string get(int key);
};


#endif //FOR_TRYING_HASHTABLE_H

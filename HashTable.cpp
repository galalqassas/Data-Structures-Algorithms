//
// Created by PC on 7/24/2023.
//

#include "HashTable.h"

HashTable::~HashTable() {
    delete[] entries;
}

void HashTable::put(int key, string& value) {
    int index = hash(key);
    auto entry = new Entry(key, value);
    for (auto entry: entries[index]){
        if (entry.key == key){
            entry.value = value;
            return;
        }
    }
    entries[index].emplace_front(*entry);
}

string HashTable::get(int key) {
    int index = hash(key);
    for (auto en: entries[index]){
        if (en.key == key){
            return en.value;
        }
    }
    return "";
}

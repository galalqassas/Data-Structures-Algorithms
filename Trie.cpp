//
// Created by PC on 2/3/2024.
//

#include "Trie.h"

void Trie::insert(std::string word) {
    Node *current = root;
    for (char ch: word) {
        if (!current->findChild(ch))
            current->addChild(ch);
        current = current->getChild(ch);
    }
    current->isEndOfWord = true;
}

bool Trie::find(std::string word) {
    Node *current = root;
    for (char ch: word) {
        if (!current->findChild(ch))
            return false;
        current = current->getChild(ch);
    }
    if (!current->isEndOfWord)
        return false;
    else {
        return true;
    }
}

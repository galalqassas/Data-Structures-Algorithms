//
// Created by PC on 2/3/2024.
//

#ifndef FOR_TRYING_TRIE_H
#define FOR_TRYING_TRIE_H

#include <string>
#include <unordered_map>

class Trie {
private:
    class Node {
    public:
        char value;
        std::unordered_map<char, Node *> children;
        bool isEndOfWord;

        Node(char c) {
            value = c;
            isEndOfWord = false;
        }

        bool findChild(char ch) {
            return !(children.find(ch) == children.end());
        }

        void addChild(char ch) {
            children[ch] = new Node(ch);
        }

        Node *getChild(char character) {
            return children[character];
        }
    };

    Node *root = new Node(' ');
public:
    void insert(std::string word);

    bool find(std::string word);
};


#endif //FOR_TRYING_TRIE_H

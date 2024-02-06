#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
    Trie trie;
    trie.insert("can");
    trie.insert("gal");
    cout << boolalpha << trie.find(nullptr);

}

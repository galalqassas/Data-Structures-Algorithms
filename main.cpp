#include <iostream>

using namespace std;

#include "HashTable.h"
#include "Heap.h"
#include "Tree.h"

int main() {
    Tree tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);
    tree.insert(3);
    tree.insert(9);
    tree.insert(10);
    tree.insert(1);
    tree.traverseInOrder();
}





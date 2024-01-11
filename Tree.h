//
// Created by PC on 1/11/2024.
//

#ifndef FOR_TRYING_TREE_H
#define FOR_TRYING_TREE_H

#include <iostream>

using namespace std;

class Tree {
private:
    class Node {
    public:
        int value;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;

        Node() {
            this->leftChild = nullptr;
            this->rightChild = nullptr;
        }

        Node(int value) {
            this->value = value;
            this->rightChild = nullptr;
            this->leftChild = nullptr;
        }

    };

    Node *root = nullptr;

    void traverseInOrder(Node *root) {
        if (root == nullptr) return;
        traverseInOrder(root->leftChild);
        cout << root->value;
        traverseInOrder(root->rightChild);
    }

    void traversePreOrder(Node *root) {
        if (root == nullptr) return;
        cout << root->value;
        traversePreOrder(root->leftChild);
        traversePreOrder(root->rightChild);
    }

public:
    void insert(Node *&root, int insertedValue) {
        if (root == nullptr) {
            root = new Node(insertedValue); // create a new node and assign it to root
            return;
        }
        if (insertedValue < root->value)
            insert(root->leftChild, insertedValue); // assign the result to the left child
        else if (insertedValue > root->value)
            insert(root->rightChild, insertedValue); // assign the result to the right child
    }

    void insert(int n) {
        insert(root, n);
    }


    void traverseInOrder() {
        traverseInOrder(root);
    }

    void traversePreOrder() {
        traversePreOrder(root);
    }

    bool equals(Node *&root, Node *&root1) {
        if (root == nullptr && root1 == nullptr) {
            return true;
        }
        if (root == nullptr && root1 != nullptr) {
            return false;
        }

        return root->value == root1->value &&
               equals(root->leftChild, root1->leftChild) &&
               equals(root->rightChild, root1->rightChild);
    }

    bool isValid(Node *root, int min = -100000, int max = 100000) {
        if (root == nullptr) {
            cout << "the tree is empty";
        }
        if (root->value < min || root->value > max) {
            return false;
        } else {
            return isValid(root->leftChild, min, root->value - 1)
                   && isValid(root->rightChild, root->value + 1, max);
        }
    }
};


#endif //FOR_TRYING_TREE_H

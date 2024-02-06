//
// Created by PC on 7/26/2023.
//

#include "AVLTree.h"
#include <iostream>
using namespace std;

void AVLTree::insert(int item) {
    insertPrivate(root, item);
}


void AVLTree::insertPrivate(AVLNode *&root, int value) {
    if (root == nullptr) {
        root = new AVLNode(value);
        return;
    }
    if (value < root->item)
        insertPrivate(root->leftChild, value);
    else // Assuming you do not want to insert duplicate values
        insertPrivate(root->rightChild, value);
    setHeight(root);
    root = balance(root);
}


AVLTree::AVLNode* AVLTree::balance(AVLTree::AVLNode *&node) {
    if (isLeftHeavy(node)) {
        if (balanceFactor(node->leftChild) < 0)
            node->leftChild = rotateLeft(node->leftChild);
        return rotateRight(node);

    } else if (isRightHeavy(node)) {
        if (balanceFactor(node->rightChild) > 0)
            node->rightChild = rotateRight(node->rightChild);
        return rotateLeft(node);
    }
    return node; // Add this line to return the node if no rotation is done
}


AVLTree::AVLNode *AVLTree::rotateLeft(AVLNode*& node) {
    AVLNode *newRoot = node->rightChild;
    node->rightChild = newRoot->leftChild;
    newRoot->leftChild = node;
    setHeight(node);
    setHeight(newRoot);
    return newRoot;
}

AVLTree::AVLNode *AVLTree::rotateRight(AVLNode*& node) {
    AVLNode* newRoot = node->leftChild;
    node->leftChild = newRoot->rightChild;
    newRoot->rightChild = node;
    setHeight(node);
    setHeight(newRoot);
    return newRoot;
}



void AVLTree::setHeight(AVLTree::AVLNode *node) {
    node->height = max(height(node->leftChild), height(node->rightChild)) + 1;
}

int AVLTree::balanceFactor(AVLNode *node) {
    if (node == nullptr) return 0;
    return height(node->leftChild) - height(node->rightChild);
}

bool AVLTree::isLeftHeavy(AVLNode *node) {
    return balanceFactor(node) > 1;
}

bool AVLTree::isRightHeavy(AVLNode *node) {
    return balanceFactor(node) < -1;
}

int AVLTree::height(AVLTree::AVLNode *node) {
    if (node == nullptr) return -1;
    return node->height;
}

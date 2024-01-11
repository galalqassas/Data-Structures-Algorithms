//
// Created by PC on 7/26/2023.
//

#include "AVLTree.h"


void AVLTree::insert(AVLTree::AVLNode* root, int item) {
    if (root == nullptr)
        root = new AVLNode(item);

    if (item < root->value)
        insert((root->left_node), item);
    if (item > root->value)
        insert((root->right_node), item);
}

void AVLTree::insert(int item) {
    insert(tree_root, item);
}

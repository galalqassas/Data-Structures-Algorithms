//
// Created by PC on 7/26/2023.
//

#ifndef FOR_TRYING_AVLTREE_H
#define FOR_TRYING_AVLTREE_H


class AVLTree {
private:
    class AVLNode{
    public:
        int value;
        AVLNode* left_node;
        AVLNode* right_node;
        explicit AVLNode(int value){
            this->value= value;
            this->right_node = nullptr;
            this->left_node = nullptr;
        }
    };
    AVLNode* tree_root = nullptr;
    void insert(AVLNode* root, int item);
public:
    void insert(int item);
};


#endif //FOR_TRYING_AVLTREE_H

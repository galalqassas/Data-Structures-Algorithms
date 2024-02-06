//
// Created by PC on 7/26/2023.
//

#ifndef FOR_TRYING_AVLTREE_H
#define FOR_TRYING_AVLTREE_H


class AVLTree {
private:
    class AVLNode{
    public:
        int item;
        AVLNode* leftChild = nullptr;
        AVLNode* rightChild = nullptr;
        int height = 0;
        explicit AVLNode(int item) {
            this->item = item;
            this->leftChild = nullptr;
            this->rightChild = nullptr;
            this->height= 0;
        }
    };
    AVLNode* root = nullptr;
    void insertPrivate(AVLNode*& root, int value);
    int height(AVLNode* node);
    int balanceFactor(AVLNode *node);
    bool isLeftHeavy(AVLNode* node);
    bool isRightHeavy(AVLNode* node);
    AVLNode* balance(AVLNode* &node);
    void setHeight(AVLNode *node);
    AVLNode *rotateRight(AVLNode*& node);
    AVLNode *rotateLeft(AVLNode*& node);
public:
    void insert(int item);
};


#endif //FOR_TRYING_AVLTREE_H

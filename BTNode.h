//
// Created by Yosiah on 24/10/2020.
//

#ifndef SENG1120_A3_BTNODE_H
#define SENG1120_A3_BTNODE_H

#include <cstdlib>

template <typename value_type>
class BTNode {
public:
    BTNode() {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    BTNode(value_type givenData, BTNode* givenParentNode = NULL) {
        data = givenData;
        parent = givenParentNode;
        leftChild = NULL;
        rightChild = NULL;
    }

    ~BTNode() {

    }

    void setData(value_type givenData) {
        data = givenData;
    }

    void setParent(BTNode* n) {
        parent = n;
    }

    void setLeftChild(BTNode* n) {
        leftChild = n;
    }

    void setRightChild(BTNode* n) {
        rightChild = n;
    }

    value_type getData() {
        return data;
    }

    BTNode* getParent() {
        return parent;
    }

    BTNode* getLeftChild() {
        return leftChild;
    }

    BTNode* getRightChild() {
        return rightChild;
    }

private:
    value_type data;
    BTNode* parent;
    BTNode* leftChild;
    BTNode* rightChild;
};

#endif //SENG1120_A3_BTNODE_H

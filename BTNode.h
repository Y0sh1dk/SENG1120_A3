//
// Created by Yosiah on 24/10/2020.
//

#ifndef BTNODE_H
#define BTNODE_H

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
        //TODO: Nothing to do here?
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

#endif //BTNODE_H

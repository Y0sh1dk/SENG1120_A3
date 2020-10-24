//
// Created by Yosiah on 24/10/2020.
//

#ifndef SENG1120_A3_BSTREE_H
#define SENG1120_A3_BSTREE_H

#include "BTNode.h"

template <typename value_type>
class BSTree {
public:
    BSTree() {
        rootNode = NULL;
    }

    BSTree(BTNode<value_type>* givenRoot) {
        rootNode = givenRoot;
    }


private:
    BTNode<value_type>* rootNode;
};

#endif //SENG1120_A3_BSTREE_H

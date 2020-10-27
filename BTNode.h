/*
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A3
 *
 * File: BTNode.h
 * Description: BTNode Declaration and Implementation
 */

#ifndef BTNODE_H
#define BTNODE_H

#include <cstdlib>

template <typename value_type>
class BTNode {
public:
    // Pre-Condition: None
    // Creates a empty BTNode
    // Post Condition: None
    BTNode() {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    // Pre-Condition: Data of given value_type, Optional parent node
    // Creates a BTNode with the given data
    // Post Condition: None
    BTNode(value_type givenData, BTNode* givenParentNode = NULL) {
        data = givenData;
        parent = givenParentNode;
        leftChild = NULL;
        rightChild = NULL;
    }

    // Pre-Condition: None
    // BTNode destructor
    // Post Condition: None
    ~BTNode() {
        //TODO: Nothing to do here?
    }

    // Pre-Condition: Data of node value type
    // Set data of the node to the given data
    // Post Condition: None
    void setData(value_type givenData) {
        data = givenData;
    }

    // Pre-Condition: A BTNode pointer
    // Set the parent of the current node to the given pointer
    // Post Condition: None
    void setParent(BTNode* n) {
        parent = n;
    }

    // Pre-Condition: A BTNode pointer
    // Sets the left child of the current node to the given pointer
    // Post Condition: None
    void setLeftChild(BTNode* n) {
        leftChild = n;
    }

    // Pre-Condition: A BTNode pointer
    // Sets the right child of the current node to the given pointer
    // Post Condition: None
    void setRightChild(BTNode* n) {
        rightChild = n;
    }

    // Pre-Condition: None
    //
    // Post Condition: Returns the data of the current node
    value_type getData() {
        return data;
    }

    // Pre-Condition: None
    //
    // Post Condition: Returns a pointer to parent node
    BTNode* getParent() {
        return parent;
    }

    // Pre-Condition: None
    //
    // Post Condition: Returns a pointer to left child
    BTNode* getLeftChild() {
        return leftChild;
    }

    // Pre-Condition: None
    //
    // Post Condition: Returns a pointer to right child
    BTNode* getRightChild() {
        return rightChild;
    }

private:
    value_type data;        // Store data
    BTNode* parent;         // Store pointer to parent node
    BTNode* leftChild;      // Store pointer to left child
    BTNode* rightChild;     // Store pointer to right child

};

#endif //BTNODE_H

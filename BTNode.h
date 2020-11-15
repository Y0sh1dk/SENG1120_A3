/**
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
    /**
     * BTNode constructor
     * Create a empty instance of BTNode
     */
    BTNode() {
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    /**
     * BTNode constructor
     * @param givenData data of given value_type to store in the node
     * @param givenParentNode a BTNode pointer to set as this nodes parent
     */
    BTNode(value_type givenData, BTNode* givenParentNode = NULL) {
        data = givenData;
        parent = givenParentNode;
        leftChild = NULL;
        rightChild = NULL;
    }

    /**
     * BTNode::~BTNode()
     * BTNode destructor, nothing to do here
     */
    ~BTNode() {
        //TODO: Nothing to do here?
    }

    /**
     * BTNode::SetData() method
     * @param givenData data of given value_type to set as the nodes data
     */
    void setData(value_type const givenData) {
        data = givenData;
    }

    /**
     * BTNode::setParent() method
     * @param n  pointer to a node to set as this nodes parent
     */
    void setParent(BTNode* const n) {
        parent = n;
    }

    /**
     * BTNode::setLeftChild() method
     * @param n  pointer to a node to set as this nodes left child
     */
    void setLeftChild(BTNode* const n) {
        leftChild = n;
    }

    /**
     * BTNode::setRightChild() method
     * @param n pointer to a node to set as this nodes right child
     */
    void setRightChild(BTNode* const n) {
        rightChild = n;
    }

    /**
     * BTNode::getData() method
     * @return a copy of the nodes data
     */
    value_type getData() const {
        return data;
    }

    /**
     * BTNode::getParent() method
     * @return a pointer to this nodes parent
     */
    BTNode* getParent() const {
        return parent;
    }

    /**
     * BTNode::getLeftChild() method
     * @return a pointer to this nodes left child
     */
    BTNode* getLeftChild() const {
        return leftChild;
    }

    /**
     * BTNode::getRightChild() method
     * @return a pointer to this nodes right child
     */
    BTNode* getRightChild() const {
        return rightChild;
    }

private:
    value_type data;        // Store data
    BTNode* parent;         // Store pointer to parent node
    BTNode* leftChild;      // Store pointer to left child
    BTNode* rightChild;     // Store pointer to right child

};

#endif //BTNODE_H

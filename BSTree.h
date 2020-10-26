//
// Created by Yosiah on 24/10/2020.
//

#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <iostream>

#include "BTNode.h"

template <typename value_type>
class BSTree {
public:
    BSTree() {
        rootNode = NULL;
    }

    BSTree(BTNode<value_type>* givenRoot) {     // If passed a tree (Node)
        rootNode = givenRoot;
    }

    ~BSTree() {
        // TODO: this
    }

    void add(value_type givenData) {
        if (rootNode == NULL) {                             // If BST empty
            rootNode = new BTNode<value_type>(givenData);   // New data will be root node
        } else {
            insert(rootNode, givenData);                    // Insert new data under root node
        }
    }

    void remove(value_type givenData)  {
        if (rootNode == NULL) {
            std::cout << "Cannot remove from a empty tree!" << std::endl;
        } else {
            removeData(givenData);
        }
    }

    std::string toString() {
        return infixTraversal(rootNode);                    // Convert tree to string with a infix traversal
    }

    void operator += (BSTree<value_type>& BSTree2) {
        std::string BSTree2String;
        BSTree2String = BSTree2.toString();                                 // Get string representation of tree
        int pos = -1;
        for (unsigned long int i = 0; i <= BSTree2String.length(); i++) {   // Loop through whole string
            if (isspace(BSTree2String[i])) {
                add(BSTree2String.substr(pos+1, i-(pos+1)));                // Add each word
                pos = i;
            }
        }
    }


private:
    BTNode<value_type>* rootNode;

    BTNode<value_type>* findNode(BTNode<value_type>* node, value_type data) {
        if (node == NULL) {
            return NULL;
        } else {
            if (node->getData() == data) {                      // if Data in current node
                return node;
            } else if (data > node->getData()) {                // Right (bigger)
                return findNode(node->getRightChild(), data);   // Recursive call with right child
            } else if (data < node->getData()) {                // Left (smaller)
                return findNode(node->getLeftChild(), data);    // Recursive call with left child
            }
        }
        return NULL; // Data doesnt exit in tree
    }

    // Find minimum node under current node
    BTNode<value_type>* minNode(BTNode<value_type>* currentNode) {
        while (currentNode->getLeftChild() != NULL) {               // While not at a leaf node
            currentNode = currentNode->getLeftChild();              // Get left child (smaller than current)
        }
        return currentNode;
    }

    // how many children does the given node have
    int howManyChildren(BTNode<value_type>* node) {
        if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {        // No children
            return 0;
        } else if (node->getLeftChild() != NULL && node->getRightChild() != NULL) { // Two children
            return 2;
        } else {                                                                    // One Child
            return 1;
        }
    }

    std::string whereUnderParent(BTNode<value_type>* node) {        // Dont like returning strings :(
        if (node->getParent()->getLeftChild() == node) {            // If the node is left of its parent
            return "LEFTCHILD";
        } else if (node->getParent()->getRightChild() == node) {    // If node is right of its parent
            return "RIGHTCHILD";
        } else {
            return NULL;                                            // Should never be called on a leaf, but just in case
        }
    }

    void removeData(value_type givenData) {
        BTNode<value_type>* node = findNode(rootNode, givenData);               // Find node with the word in it
        if (node == NULL) {                                                     // Word doesnt exist!
            return;
        }
        if (howManyChildren(node) == 0) {                                       // ----CASE 1 - LEAF NODE----
            if (node == rootNode) {                                             // Root node
                delete(rootNode);
                rootNode = NULL;
            } else {                                                            // Not root node
                if (whereUnderParent(node) == "LEFTCHILD") {                    // Left node of parent
                    node->getParent()->setLeftChild(NULL);                      // Set parents new child
                    delete(node);
                } else if (whereUnderParent(node) == "RIGHTCHILD") {            // Right node of parent
                    node->getParent()->setRightChild(NULL);                     // Set parents new child
                    delete(node);
                }
            }
        } else if (howManyChildren(node) == 1) {                                // ----CASE 2 - ONE CHILD----
            if (node == rootNode) {                                             // Deleting the root node
                if (node->getRightChild() != NULL) {                            // If the one child is in right node
                    rootNode = node->getRightChild();                           // Set new root node
                    rootNode->setParent(NULL);
                    delete(node);
                } else if (node->getLeftChild() != NULL) {                      // If the one child is in left node
                    rootNode = node->getLeftChild();                            // Set new root node
                    rootNode->setParent(NULL);
                    delete(node);
                }
            } else {                                                            // Not root node
                if (node->getRightChild() != NULL) {                            // In right child
                    if (whereUnderParent(node) == "LEFTCHILD") {                // Left node of parent
                        node->getParent()->setLeftChild(node->getRightChild()); // Set parents new child
                        node->getRightChild()->setParent(node->getParent());    // Set child's new parent
                        delete(node);
                    } else if (whereUnderParent(node) == "RIGHTCHILD") {        // Right node of parent
                        node->getParent()->setRightChild(node->getRightChild());// Set parents new child
                        node->getRightChild()->setParent(node->getParent());    // Set child's new parent
                        delete(node);
                    }
                } else if (node->getLeftChild() != NULL) {                      // In left child
                    if (whereUnderParent(node) == "LEFTCHILD") {                // Left node of parent
                        node->getParent()->setLeftChild(node->getLeftChild());  // Set parents new child
                        node->getLeftChild()->setParent(node->getParent());     // Set child's new parent
                        delete(node);
                    } else if (whereUnderParent(node) == "RIGHTCHILD") {        // Right node of parent
                        node->getParent()->setRightChild(node->getLeftChild()); // Set parents new child
                        node->getLeftChild()->setParent(node->getParent());     // Set child's new parent
                        delete(node);
                    }
                }
            }
        } else if (howManyChildren(node) == 2) {                                // ----CASE 3 - TWO CHILDREN----
            BTNode<value_type>* minRightNode = minNode(node->getRightChild());  // Get smallest node on the right
            value_type temp = minRightNode->getData();                          // Store data in temp as node is getting deleted
            removeData(minRightNode->getData());                                // recursive call
            node->setData(temp);                                                // Set data of 'deleted' node
        }
    }

    value_type infixTraversal(BTNode<value_type>* node) {
        if (node == NULL) {
            return "";
        } else {
            // Recursive call to left and right child, getting node data in between, therefore 'Infix'
            return infixTraversal(node->getLeftChild()) + node->getData() + " " + infixTraversal(node->getRightChild());
        }
    }

    void insert(BTNode<value_type>* node, value_type givenData) {
        if (node == NULL) {
            return;
        } else {
            if (givenData == node->getData()) {                                     // If data is same as node
                node->setData(givenData);                                           // Replace data
            } else if (givenData > node->getData()) {                               // right
                if (node->getRightChild() == NULL) {
                    node->setRightChild(new BTNode<value_type>(givenData, node));   // insert at right
                } else {
                    insert(node->getRightChild(), givenData);                       // recursive call with node as right child
                }
            } else if (givenData < node->getData()) {                               // left
                if (node->getLeftChild() == NULL) {
                    node->setLeftChild(new BTNode<value_type>(givenData, node));    // insert at left
                } else {
                    insert(node->getLeftChild(), givenData);                        // recursive call with node as left child
                }
            }
        }
    }

};


template <typename value_type>
std::ostream& operator << (std::ostream& out, BSTree<value_type> tree) {
    std::string treeString = tree.toString();                                       // Get string representation of tree
    out << treeString;
    return out;
}

#endif //BSTREE_H

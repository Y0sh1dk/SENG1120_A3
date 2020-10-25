//
// Created by Yosiah on 24/10/2020.
//

#ifndef SENG1120_A3_BSTREE_H
#define SENG1120_A3_BSTREE_H

#include <ostream>
#include "BTNode.h"

template <typename value_type>
class BSTree {
public:
    BSTree() {
        rootNode = NULL;
    }

    BSTree(BTNode<value_type>* givenRoot) { // if already passed a tree (Node)
        rootNode = givenRoot;
    }

    void add(value_type givenData) {
        if (rootNode == NULL) {
            rootNode = new BTNode<value_type>(givenData);
        } else {
            insert(rootNode, givenData);
        }
    }

    void insert(BTNode<value_type>* node, value_type givenData) { // TODO: make private?
        if (node == NULL) {
            return;
        } else {
            if (givenData == node->getData()) {
                node->setData(givenData);                                   // Replace data
            } else if (givenData > node->getData()) {                       // right
                if (node->getRightChild() == NULL) {
                    node->setRightChild(new BTNode<value_type>(givenData, node)); // insert at right
                } else {
                    insert(node->getRightChild(), givenData);               // recursive call with node as right child
                }
            } else if (givenData < node->getData()) {                       // left
                if (node->getLeftChild() == NULL) {
                    node->setLeftChild(new BTNode<value_type>(givenData, node));  // insert at left
                } else {
                    insert(node->getLeftChild(), givenData);                // recursive call with node as left child
                }
            }
        }
    }

    void remove(value_type givenData) {
        BTNode<value_type>* dataNode = findNode(rootNode, givenData);
        if (dataNode != NULL) { // If the word was found
//            std::cout << dataNode->getData() << std::endl;
            if (dataNode->getLeftChild() == NULL && dataNode->getRightChild() == NULL) { // leaf node
                if (dataNode != rootNode) {
                    if (dataNode->getParent()->getLeftChild() == dataNode) { // if parents left child is this node
                        dataNode->getParent()->setLeftChild(NULL);
                    } else if (dataNode->getParent()->getRightChild() == dataNode) { // if parents right child is this node
                        dataNode->getParent()->setRightChild(NULL);
                    }
                    delete(dataNode);
                } else { // If deleting root node
                    delete(rootNode);
                    rootNode = NULL;
                }
            } else if ((dataNode->getLeftChild() == NULL) != (dataNode->getRightChild() == NULL)) { // Node with 1 child
                if (dataNode->getLeftChild() != NULL) { // data is in left child
                    if (dataNode != rootNode) {
                        if (dataNode->getParent()->getLeftChild() == dataNode) {
                            dataNode->getParent()->setLeftChild(dataNode->getLeftChild());
                        } else if (dataNode->getParent()->getRightChild() == dataNode) {
                            dataNode->getParent()->setRightChild(dataNode->getLeftChild());
                        }
                        delete(dataNode);
                    } else { // is root node
                        rootNode = dataNode->getLeftChild();
                        delete(dataNode);
                    }
                } else if (dataNode->getRightChild() != NULL) { // data is in right child
                    if (dataNode != rootNode) {
                        if (dataNode->getParent()->getLeftChild() == dataNode) {
                            dataNode->getParent()->setLeftChild(dataNode->getRightChild());
                        } else if (dataNode->getParent()->getRightChild() == dataNode) {
                            dataNode->getParent()->setRightChild(dataNode->getLeftChild());
                        }
                        delete(dataNode);
                    } else { // is root node
                        rootNode = dataNode->getRightChild();
                        delete(dataNode);
                    }
                }
            } else if ((dataNode->getLeftChild() != NULL) && (dataNode->getRightChild() != NULL)) { // has two childs
                //TODO: get min node on right of current node
                BTNode<value_type>* minRightNode = minNode(dataNode->getRightChild());
                value_type temp = minRightNode->getData();
                remove(minRightNode->getData());
                dataNode->setData(temp);
            }
        }

    }

    std::string toString() {
        return infixTraversal(rootNode);
    }

    value_type infixTraversal(BTNode<value_type>* node) { // TODO: make private?
        if (node == NULL) {
            return "";
        } else {
            return infixTraversal(node->getLeftChild()) + node->getData() + " " + infixTraversal(node->getRightChild());
        }
    }

    void operator += (BSTree<value_type>& BSTree2) {
        std::string BSTree2String;
        BSTree2String = BSTree2.toString();
        int pos = -1;
        for (unsigned long int i = 0; i <= BSTree2String.length(); i++) {
            if (isspace(BSTree2String[i])) {
                add(BSTree2String.substr(pos+1, i-(pos+1)));
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
            if (node->getData() == data) {
                return node;
            } else if (data > node->getData()) { // right
                return findNode(node->getRightChild(), data);
            } else if (data < node->getData()) { // left
                return findNode(node->getLeftChild(), data);
            }
        }
    }

    BTNode<value_type>* minNode(BTNode<value_type>* currentNode) { // Find minimum node under current node
        while (currentNode->getLeftChild() != NULL) {
            currentNode = currentNode->getLeftChild();
        }
        return currentNode;
    }

};

template <typename value_type>
std::ostream& operator << (std::ostream& out, BSTree<value_type> tree) {
    std::string treeString = tree.toString();
    out << treeString;
    return out;
}

#endif //SENG1120_A3_BSTREE_H

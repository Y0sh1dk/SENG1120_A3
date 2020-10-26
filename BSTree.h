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
            if (givenData == node->getData()) { // TODO:Breaks here when comparing ""
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

    void remove(value_type givenData)  {
        if (rootNode == NULL) {
            std::cout << "Cannot remove from a empty tree!" << std::endl;
        } else {
            removeData(rootNode, givenData);
        }
    }

    void removeData(BTNode<value_type>* node, value_type givenData) { // TODO: Make private??
        if (howManyChildren(node) == 0) {               // leaf node
            if (node == rootNode) {                     // Root node
                delete(rootNode);
                rootNode = NULL;
            } else {                                    // Not root node
                if (whereUnderParent(node) == "LEFTCHILD") {
                    node->getParent()->setLeftChild(NULL);
                    delete(node);
                } else if (whereUnderParent(node) == "RIGHTCHILD") {
                    node->getParent()->setRightChild(NULL);
                }
            }
        } else if (howManyChildren(node) == 1) {        // one child
            if (node == rootNode) { // root node
                if (node->getRightChild() != NULL) {
                    rootNode = node->getRightChild();
                    rootNode->setParent(NULL);
                    delete(node);
                } else if (node->getLeftChild() != NULL) {
                    rootNode = node->getLeftChild();
                    rootNode->setParent(NULL);
                    delete(node);
                }
            } else { // Not root node
                if (node->getRightChild() != NULL) { // In right child
                    if (whereUnderParent(node) == "LEFTCHILD") {
                        node->getParent()->setLeftChild(node->getRightChild());
                        node->getRightChild()->setParent(node->getParent());
                        delete(node);
                    } else if (whereUnderParent(node) == "RIGHTCHILD") {
                        node->getParent()->setRightChild(node->getRightChild());
                        node->getRightChild()->setParent(node->getParent());
                        delete(node);
                    }
                } else if (node->getLeftChild() != NULL) { // In left child
                    if (whereUnderParent(node) == "LEFTCHILD") {
                        node->getParent()->setLeftChild(node->getLeftChild());
                        node->getLeftChild()->setParent(node->getParent());
                        delete(node);
                    } else if (whereUnderParent(node) == "RIGHTCHILD") {
                        node->getParent()->setRightChild(node->getLeftChild());
                        node->getLeftChild()->setParent(node->getParent());
                        delete(node);
                    }
                }
            }
        } else if (howManyChildren(node) == 2) {        // two children
            BTNode<value_type>* minRightNode = minNode(node->getRightChild());
            value_type temp = minRightNode->getData();
            removeData(minRightNode ,minRightNode->getData()); // recursive call
            node->setData(temp);
        }
    }














//    void remove(value_type givenData) {
//        BTNode<value_type>* dataNode = findNode(rootNode, givenData);
//        if (dataNode != NULL) { // If the word was found
////            std::cout << dataNode->getData() << std::endl;
//            if (dataNode->getLeftChild() == NULL && dataNode->getRightChild() == NULL) { // leaf node
//                if (dataNode != rootNode) {
//                    if (dataNode->getParent()->getLeftChild() == dataNode) { // if parents left child is this node
//                        dataNode->getParent()->setLeftChild(NULL);
//                    } else if (dataNode->getParent()->getRightChild() == dataNode) { // if parents right child is this node
//                        dataNode->getParent()->setRightChild(NULL);
//                    }
//                    delete(dataNode);
//                } else { // If deleting root node
//                    delete(rootNode);
//                    rootNode = NULL;
//                }
//            } else if ((dataNode->getLeftChild() == NULL) != (dataNode->getRightChild() == NULL)) { // Node with 1 child
//                if (dataNode->getLeftChild() != NULL) { // data is in left child
//                    if (dataNode != rootNode) {
//                        if (dataNode->getParent()->getLeftChild() == dataNode) {
//                            dataNode->getParent()->setLeftChild(dataNode->getLeftChild());
//                        } else if (dataNode->getParent()->getRightChild() == dataNode) {
//                            dataNode->getParent()->setRightChild(dataNode->getLeftChild());
//                        }
//                        delete(dataNode);
//                    } else { // is root node
//                        rootNode = dataNode->getLeftChild();
//                        delete(dataNode);
//                    }
//                } else if (dataNode->getRightChild() != NULL) { // data is in right child
//                    if (dataNode != rootNode) {
//                        if (dataNode->getParent()->getLeftChild() == dataNode) {
//                            dataNode->getParent()->setLeftChild(dataNode->getRightChild());
//                        } else if (dataNode->getParent()->getRightChild() == dataNode) {
//                            dataNode->getParent()->setRightChild(dataNode->getRightChild());
//                        }
//                        delete(dataNode);
//                    } else { // is root node
//                        rootNode = dataNode->getRightChild();
//                        delete(dataNode);
//                    }
//                }
//            } else if ((dataNode->getLeftChild() != NULL) && (dataNode->getRightChild() != NULL)) { // has two childs
//                //TODO: get min node on right of current node
//                BTNode<value_type>* minRightNode = minNode(dataNode->getRightChild());
//                value_type temp = minRightNode->getData();
//                remove(minRightNode->getData()); // recursive call
//                dataNode->setData(temp);
//            }
//        }
//    }

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

    int howManyChildren(BTNode<value_type>* node) { // how many children does the node have
        if (node->getLeftChild() == NULL && node->getRightChild() == NULL) {
            return 0;
        } else if (node->getLeftChild() != NULL && node->getRightChild() != NULL) {
            return 2;
        } else {
            return 1;
        }
    }

    std::string whereUnderParent(BTNode<value_type>* node) { // HATE returning string but oh well
        if (node->getParent()->getLeftChild() == node) {
            return "LEFTCHILD";
        } else if (node->getParent()->getRightChild() == node) {
            return "RIGHTCHILD";
        }
    }

};


template <typename value_type>
std::ostream& operator << (std::ostream& out, BSTree<value_type> tree) {
    std::string treeString = tree.toString();
    out << treeString;
    return out;
}

#endif //SENG1120_A3_BSTREE_H

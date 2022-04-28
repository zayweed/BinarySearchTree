#include <bits/stdc++.h>
#include "node.h"

using namespace std;

Node::Node(int newValue) {
    value = newValue;
    left = NULL;
    right = NULL;
}

Node* Node::getLeft() { //getter for left node
    return left;
}

Node* Node::getRight() { //getter for right node
    return right;
}

int Node::getValue() { //getter for value
    return value;
}

void Node::setLeft(Node* newLeft) { //setter for left node
    left = newLeft;
}

void Node::setRight(Node* newRight) { //setter for right node
    right = newRight;
}

void Node::setValue(int newValue) { //setter for value
    value = newValue;
}
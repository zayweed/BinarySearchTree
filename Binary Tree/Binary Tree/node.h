#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>

using namespace std;

class Node {
  private:
    int value;
    Node* left;
    Node* right;

  public:
    Node(int newValue); //constructer
    //getters
    Node* getLeft();
    Node* getRight();
    int getValue();
    //setters
    void setLeft(Node* newLeft);
    void setRight(Node* newRight);
    void setValue(int newValue);

};

#endif
/*
Zayeed Saffat
4/24/2022
This project uses a binary tree to sort integers using nodes. Each node has a left and right child along with a value.
Credits to Ruby Amyeen for help with the delete function.
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "node.h"

using namespace std;

void add(Node*& head, Node* current, int num);
void display(Node* current, int depth);
Node* remove(Node* current, int value);
bool search(Node* head, int value);

int main() {
    Node* head = NULL;

    bool stillPlaying = true;
    while (stillPlaying == true) {
        cout << "Would you like to add by file(FILE), add by input(INPUT), display the tree(DISPLAY), remove a node(REMOVE), search for a node(SEARCH), or quit(QUIT)?" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "FILE") == 0) { //add by file
            cout << "Enter how many integers you would like to add:" << endl;
            int n; cin >> n;
            fstream fin;
            fin.open("numbers.txt"); //open file

            int value;
            for (int i = 0; i < n; i++) { //iterates through the first n integers in the file
                fin >> value;
                add(head, head, value);
            }

            fin.close(); //close file
        }

        if (strcmp(input, "INPUT") == 0) { //add by input
            cout << "Enter how many you integers would like to add:" << endl;
            int n; cin >> n;

            cout << "Enter the integers:" << endl;
            int value;
            for (int i = 0; i < n; i++) {
                cin >> value;
                add(head, head, value);
            }
        }

        if (strcmp(input, "DISPLAY") == 0) { //display tree
            display(head, 0);
        }

        if (strcmp(input, "REMOVE") == 0) { //delete an integer from tree
            cout << "Enter an integer to REMOVE:" << endl;
            int value; cin >> value;

            head = remove(head, value);
        }

        if (strcmp(input, "SEARCH") == 0) { //search for an integer
            cout << "Enter an integer to search for:" << endl;
            int value; cin >> value; 
            if (search(head, value) == true) { //value found in tree
                cout << "Integer is in the tree!" << endl;
            }           
            else { //value not found in tree
                cout << "Integer is not in the tree!" << endl;
            }
        }

        if (strcmp(input, "QUIT") == 0) { //quit
            stillPlaying = false;
        }

    }
}

void add(Node*& head, Node* current, int value) { //function that adds integer to tree
    if (head == NULL) { //if tree is empty and head is NULL
        head = new Node(value);
    }

    else if (value < current->getValue()) { //if value is less than current
        if (current->getLeft() == NULL) { //add value to tree
            current->setLeft(new Node(value));
        }
        else { //go left
            add(head, current->getLeft(), value);
        }
    }

    else if (value > current->getValue()) { //if value is greater than current
        if (current->getRight() == NULL) { //add value to tree
            current->setRight(new Node(value));
        }
        else { //go right
            add(head, current->getRight(), value);
        }
    }
}

void display(Node* current, int depth) { //function that displays tree
    if (current == NULL) { //if tree is empty and head is NULL exit function
        return;
    }

    if (current->getRight() != NULL) {
        display(current->getRight(), depth+1); //recursive call
    }

    for (int i = 0; i < depth; i++) { //print tabs based on depth
        cout << "\t";
    }
    cout << current->getValue() << endl; //print current value

    if (current->getLeft() != NULL) {
        display(current->getLeft(), depth+1); //recursive call
    }
}

Node* remove(Node* current, int value) { //function that removes a value from the tree
    if (current == NULL) { //if tree is empty and head is NULL exit function
        cout << "Integer is not in the tree!" << endl;
        return current;
    } 

    else if (value < current->getValue()) { //if value is less than current go left
        current->setLeft(remove(current->getLeft(), value));
    } 

    else if (value > current->getValue()) { //if value is greater than current go right
        current->setRight(remove(current->getRight(), value));
    } 

    else { //value is found
        if (current->getLeft() == NULL && current->getRight() == NULL) { //if node has no children
            return NULL;
        } 
        else if (current->getLeft() == NULL) { //if node has no left child
            Node* temp = current->getRight();
            delete current;
            return temp;
        } 
        else if (current->getRight() == NULL) { //if node has no right child
            Node* temp = current->getLeft();
            delete current;
            return temp;
        }

        //find smallest node larger than current
        Node* temp = current->getRight();
        while (temp != NULL && temp->getLeft() != NULL) {
            temp = temp->getLeft();
        }
        current->setValue(temp->getValue()); //update current
        current->setRight(remove(current->getRight(), temp->getValue())); //recursive call
    }

    return current;
}

bool search(Node* head, int value) { //function that searches for a value in the tree
    Node* current = head;
    while (current != NULL) {
        if (value < current->getValue()) { //if value is less than current go left
            current = current->getLeft();
        }
        else if (value > current->getValue()) { //if value is greater than current go right
            current = current->getRight();
        }
        else if (value == current->getValue()) { //value is found and true is returned
            return true;
        }
    }
    return false; //if NULL node is reached without finding the value then we know it doesn't exist in the tree
}

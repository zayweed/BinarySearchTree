#include <bits/stdc++.h>
#include "node.h"

using namespace std;

void add(Node*& head, Node* current, int num);
void display(Node* current, int depth);
bool search(Node* head, int value);

int main() {
    Node* head = NULL;

    bool stillPlaying = true;
    while (stillPlaying == true) {
        cout << "Would you like to add by file(FILE), input(INPUT), display the tree(DISPLAY), delete a node(DELETE), search for a node(SEARCH), or quit(QUIT)?" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "FILE") == 0) {
            cout << "How many integers would you like to add:" << endl;
            int n; cin >> n;
            fstream fin;
            fin.open("numbers.txt"); 

            int value;
            for (int i = 0; i < n; i++) {
                fin >> value;
                add(head, head, value);
                //cout << num << endl;
            }

            fin.close();
        }

        if (strcmp(input, "INPUT") == 0) {
            cout << "How many integers would you like to add:" << endl;
            int n; cin >> n;

            cout << "Enter the integers:" << endl;
            int value;
            for (int i = 0; i < n; i++) {
                cin >> value;
                add(head, head, value);
            }
        }

        if (strcmp(input, "DISPLAY") == 0) {
            display(head, 0);
        }

        if (strcmp(input, "DELETE") == 0) {
            
        }

        if (strcmp(input, "SEARCH") == 0) {
            cout << "Enter an integer to search for:" << endl;
            int value; cin >> value; 
            if (search(head, value) == true) {
                cout << "Integer is in the tree!" << endl;
            }           
            else {
                cout << "Integer is not in the tree!" << endl;
            }
        }

        if (strcmp(input, "QUIT") == 0) {
            stillPlaying = false;
        }

    }
}

void add(Node*& head, Node* current, int value) {
    if (head == NULL) { //if tree is empty and head is NULL
        head = new Node(value);
    }

    else if (value < current->getValue()) {
        if (current->getLeft() == NULL) {
            current->setLeft(new Node(value));
        }
        else {
            add(head, current->getLeft(), value);
        }
    }

    else if (value > current->getValue()) {
        if (current->getRight() == NULL) {
            current->setRight(new Node(value));
        }
        else {
            add(head, current->getRight(), value);
        }
    }
}

void display(Node* current, int depth) {
    if (current == NULL) {
        return;
    }

    if (current->getRight() != NULL) {
        display(current->getRight(), depth+1);
    }

    for (int i = 0; i < depth; i++) {
        cout << "\t";
    }
    cout << current->getValue() << endl;

    if (current->getLeft() != NULL) {
        display(current->getLeft(), depth+1);
    }
}

bool search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (value < current->getValue()) { //if value is less than current than we must go left
            current = current->getLeft();
        }
        else if (value > current->getValue()) { //if value is greater than current than we must go right
            current = current->getRight();
        }
        else if (value == current->getValue()) { //value is found and true is returned
            return true;
        }
    }
    return false; //if NULL node is reached without finding the value then we know it doesn't exist in the tree
}

/*

*/
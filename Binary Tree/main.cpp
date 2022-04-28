#include <bits/stdc++.h>
#include "node.h"

using namespace std;

void add(Node* current, int num);
void display(Node* current, int depth);

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

            int num;
            for (int i = 0; i < n; i++) {
                fin >> num;
                add(head, num);
                //cout << num << endl;
            }

            fin.close();
        }

        if (strcmp(input, "INPUT") == 0) {
            cout << "How many integers would you like to add:" << endl;
            int n; cin >> n;

            cout << "Enter the integers:" << endl;
            int num;
            for (int i = 0; i < n; i++) {
                cin >> num;
                add(head, num);
            }
        }

        if (strcmp(input, "DISPLAY") == 0) {
            display(head, 0);
        }

        if (strcmp(input, "DELETE") == 0) {
            
        }

        if (strcmp(input, "SEARCH") == 0) {
            
        }

        if (strcmp(input, "QUIT") == 0) {
            stillPlaying = false;
        }

    }
}

void add(Node* current, int value) {
    if (current == NULL) { //if tree is empty and head is NULL
        current = new Node(value);
    }

    else if (value < current->getValue()) {
        if (current->getLeft() == NULL) {
            current->setLeft(new Node(value));
        }
        else {
            add(current->getLeft(), value);
        }
    }

    else if (value > current->getValue()) {
        if (current->getRight() == NULL) {
            current->setRight(new Node(value));
        }
        else {
            add(current->getRight(), value);
        }
    }
}

void display(Node* current, int depth) {
    if (current->getRight() != NULL) {
        display(current->getRight(), depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        cout << "\t";
    }
    cout << current->getValue() << endl;

    if (current->getLeft() != NULL) {
        display(current->getLeft(), depth + 1);
    }
}
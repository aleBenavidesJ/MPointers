#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "MPointer.h"

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        MPointer<T> data;
        Node* next;
        Node* prev;
        Node(const MPointer<T>& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    template <typename U>
    friend class Sorters;

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }

    void append(const MPointer<T>& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printForward() const {
        Node* current = head;
        while (current) {
            std::cout << "Value: " << current->data << std::endl;
            current = current->next;
        }
    }

    void printBackward() const {
        Node* current = tail;
        while (current) {
            std::cout << "Value: " << current->data << std::endl;
            current = current->prev;
        }
    }
};
#endif //DOUBLYLINKEDLIST_H

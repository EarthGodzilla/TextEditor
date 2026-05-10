#pragma once
#include <stdexcept>
using std::underflow_error;
using std::cout;
using std::string;

template <typename T>
class CircularLinkedStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* topNode = nullptr;
    int count = 0;

public:
    CircularLinkedStack() = default;
    CircularLinkedStack(const CircularLinkedStack& other) {
        if (!other.topNode) return;

        Node* curr = other.topNode->next;
        do {
            push(curr->data);
            curr = curr->next;
        } while (curr != other.topNode->next);
    }

    CircularLinkedStack& operator=(const CircularLinkedStack& other) {
        if (this == &other) return *this;

        while (!isEmpty()){
            pop();
        } // clean  mem

        if (!other.topNode){
            return *this;
        }
        
        Node* curr = other.topNode->next;
        do {
            push(curr->data);
            curr = curr->next;
        } while (curr != other.topNode->next);

        return *this;
    }


    void push(const T& item) {
        Node* newNode = new Node(item);

        if (!topNode) {
            newNode->next = newNode;
            topNode = newNode;
        } else {
            newNode->next = topNode->next;
            topNode->next = newNode;
            topNode = newNode;
        }

        ++count;
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack empty");
        }

        Node* nodeToDelete;
        T value;
        if (count == 1) {
            nodeToDelete = topNode;
            value = nodeToDelete->data;
            topNode = nullptr; // now empty
        } else {
            nodeToDelete = topNode->next;
            value = nodeToDelete->data;
            topNode->next = nodeToDelete->next;
        }

        delete nodeToDelete;
        count--;
        return value;
    }

    T top() const {
        if (isEmpty()){
            throw underflow_error("Stack empty");
        }

        return topNode->/*next->*/data;
    }

    bool isEmpty() const { 
        return count == 0; 
    }

    int size() const { 
        return count; 
    }

    ~CircularLinkedStack() {
        while (!isEmpty()){
            pop();
        }
    }
};
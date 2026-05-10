#pragma once
#include <stdexcept>
using std::underflow_error;
using std::cout;
using std::string;

template <typename T>
class CircularLinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* rear = nullptr;
    int count = 0;

public:
    CircularLinkedQueue() = default;
    CircularLinkedQueue(const CircularLinkedQueue&) = delete;
    CircularLinkedQueue& operator=(const CircularLinkedQueue&) = delete;

    void enqueue(const T& item) {
        Node* newNode = new Node(item);

        if (!rear) {
            newNode->next = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
        }

        rear = newNode;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue empty");
        }

        Node* front = rear->next;
        T value = front->data;

        if (rear == front)
            rear = nullptr;
        else
            rear->next = front->next;

        delete front;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            throw underflow_error("Queue empty");
        }
        return rear->next->data;
    }

    bool isEmpty() const { 
        return count == 0; 
    }

    int size() const { 
        return count; 
    }

    ~CircularLinkedQueue() {
        while (!isEmpty()){
            dequeue();
        }
    }
};
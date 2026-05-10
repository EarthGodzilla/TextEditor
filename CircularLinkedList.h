#pragma once
#include <iostream>
#include <stdexcept>
using std::underflow_error;
using std::cout;
using std::string;

template <typename T>
class CircularLinkedList {
    public:
    CircularLinkedList() = default;
    CircularLinkedList(const CircularLinkedList&) = delete;
    CircularLinkedList& operator=(const CircularLinkedList&) = delete;
    
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    
    private:
    Node* head = nullptr;
    int count = 0;

    public:
    Node* getHead() const {
        return head;
    }

    void insertFront(const T& item) {
        Node* newNode = new Node(item);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head){
                 temp = temp->next;
            
            }

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        count++;
    }

    void insertRear(const T& item) {
        Node* newNode = new Node(item);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head){
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }

    void deleteFront() {
        if (isEmpty()){ 
            throw underflow_error("List empty");
        }
        
        if (count == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* last = head;

            while (last->next != head){
                last = last->next;
            }

            head = head->next;
            last->next = head;
            delete temp;
        }
        count--;
    }

    void deleteRear() {
        if (isEmpty()){
             throw underflow_error("List empty");
            }

        if (count == 1) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;

            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = head;
            delete temp;
        }
        count--;
    }

    void display() const {
        if (!head){
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }

    bool isEmpty() const { 
        return count == 0; 
    }

    int size() const { 
        return count; 
    }

    ~CircularLinkedList() {
        while (!isEmpty()){
            deleteFront();
        }
    }
};
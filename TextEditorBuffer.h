#pragma once
#include "circularLinkedStack.h"
#include "circularLinkedQueue.h"
#include "CircularLinkedList.h"
#include <iostream>
#include <string>

using std::underflow_error;
using std::cout;
using std::string;

template <typename T>
class TextEditorBuffer {
private:
    CircularLinkedStack<T> buffer;
    CircularLinkedQueue<T> redoQueue;
    CircularLinkedList<string> history; 

public:
    void type(const T& item) {
        buffer.push(item);
        history.insertRear("Typed item");
    }

    void undo() {
        if (buffer.isEmpty()) {
            cout << "Nothing to undo\n";
            return;
        }
        T item = buffer.pop();
        redoQueue.enqueue(item);
        history.insertRear("Undo");
        cout << "Undo: Removed " << item << "\n";
    }

    void redo() {
        if (redoQueue.isEmpty()) {
            cout << "Nothing to redo\n";
            return;
        }
        T item = redoQueue.dequeue();
        buffer.push(item);
        history.insertRear("Redo");
        cout << "Redo: Added " << item << "\n";
    }

    void displayBuffer() const {
        cout << "Buffer: ";

        if (buffer.isEmpty()) {
            cout << "(empty)\n";
            return;
        } else {
            //CircularLinkedStack<T> temp = buffer;
            CircularLinkedStack<T> temp(buffer);
            CircularLinkedStack<T> reversed;

            while (!temp.isEmpty()){ 
                reversed.push(temp.pop());
            }
            while (!reversed.isEmpty()){ 
                cout << reversed.pop();
            }
        }
        cout << "\n";
    }
    

    void displayHistory() const {
        cout << "History: ";
        if (history.isEmpty()) {
            cout << "(none)";
        } else {
            typename CircularLinkedList<string>::Node* current = history.getHead();
            typename CircularLinkedList<string>::Node* start = current; // remember start

            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != start);
        }
        cout << "\n";
    }
};
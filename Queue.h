#pragma once
#include <stdexcept>
using std::underflow_error;
using std::overflow_error; 
using std::cout;
using std::string;

template <typename T>
class Queue {
private:
    T* arr;
    int capacity;
    int frontIndex = 0, rearIndex = -1, count = 0;

public:
    Queue(int cap = 100) : capacity(cap) {
        arr = new T[capacity];
    }

    void enqueue(const T& item) {
        if (isFull()) {
            throw overflow_error("Queue full");
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue empty");
        }

        T value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return value;
    }

    T front() const {
        if (isEmpty()) {
            throw underflow_error("Queue empty");
        }
        return arr[frontIndex];
    }

    bool isEmpty() const { 
        return count == 0; 
    }

    bool isFull() const { 
        return count == capacity; 
    }

    int size() const { 
        return count; 
    }

    ~Queue(){ 
        delete[] arr; 
    }
};
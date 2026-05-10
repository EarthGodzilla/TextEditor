#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

template <typename T>
class Stacker{
    //i should do the array one
    //TODO: Delete Later
    /*struct Node { 
    ItemType data;
    Node* next;

    Node(ItemType item) : data(item), next(nullptr) {}
        }; */

    private:
        T *data;
      //  Stacker* next;
        int size9, capacity;
    public:
    //    int size=0, capacity=100;
    Stack():size9(0), capacity(100){data = new T[capacity]}
        void pusher(T data);
        T pop();
        T top();
        bool isEmpty();
        bool isfull();
        int getSize();
        ~Stack() {delete[] data;}
};

#endif
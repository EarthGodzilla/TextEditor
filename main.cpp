
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "CircularLinkedList.h"
#include "circularLinkedStack.h"
#include "circularLinkedQueue.h"
#include "TextEditorBuffer.h"

using std::underflow_error;
using std::cout;
using std::string;
using std::exception;

int main() {
    try {
        Stack<int> s;
        Queue<int> q;
        CircularLinkedList<int> list;
        TextEditorBuffer<char> editor; 

        cout << "STACK TEST:\n";

        for (int i = 1; i <= 3; i++) {
            s.push(i);
        }
        s.pop();

        cout << "Top: " << s.top() << " Size: " << s.size() << "\n\n";

        cout << "QUEUE TEST:\n";
        q.enqueue(4); 
        q.enqueue(5);
        q.dequeue();
        cout << "Front: " << q.front() << " Size: " << q.size() << "\n\n";

        cout << "CIRCULAR LINKED LIST TEST:\n";
        
        list.insertRear(0);
        list.insertRear(1);
        list.insertRear(2);
        list.insertRear(3);
        list.deleteFront();
        list.deleteRear();

        cout << "List: ";
        list.display();

        cout << "\nTEXT EDITOR TEST:\n";

        string text = "helloworld";
        for (char c : text){
            editor.type(c);
        }

        editor.displayBuffer();
        for (int i = 1; i <= 3; i++) {
            editor.undo();
        }
        cout << "After Undo: ";
        editor.displayBuffer();
        
        for (int i = 1; i <= 2; i++) {
            editor.redo();
        }
        
        cout << "After Redo: ";
        editor.displayBuffer();

        cout << "History: ";
        editor.displayHistory();

    } catch (const exception& e) {
        cout << e.what();
    }

    return 0;
}
#include <iostream>
#include "TextEditor.h"
//#include <vector>

//using namespace std;

using std::cout;
using std::string;


string stringArr[100];
template <typename T>
/*
bool isEmpty(){
    return size92==0;
}
bool isFull(){
    return size9==capacity;
}
void pop(){}{

}

int getSize(){}

T top(){}*/

void pusher(T data){
    //string stringArr[capacity];

    if (size9=capacity||size9>capacity){
        stringArr[capacity]= new stringArr[capacity*2];
    }

    stringArr[capacity]=data;
    size9++;


}
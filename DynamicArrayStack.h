#ifndef DYNAMIC_ARRAY_STACK
#define DYNAMIC_ARRAY_STACK

#include "Stack.h"
#include <assert.h>
#include "StackOverflowException.h"
#include "StackUnderflowException.h"

#include <iostream>
using namespace std;

template <class T>
class DynamicArrayStack : public Stack<T>
{
    private:
        int top;
        int CAPACITY;
        T* storage;

        void resize(int nCAPACITY); // only called internally

    public:
        DynamicArrayStack();
        DynamicArrayStack(int _CAPACITY);
        ~DynamicArrayStack();

        void push(const T&);
        void pop();
        T peek() const;
        bool isEmpty() const;
        bool isFull() const;


};
//default constructor with top at undefined index, with default capacity set to 1
template <class T>
DynamicArrayStack<T>::DynamicArrayStack():top(-1), CAPACITY(1)
{
    storage = new T[CAPACITY];
}
//constructor with top at undefined index but a defined initial capacity
template <class T>
DynamicArrayStack<T>::DynamicArrayStack(int _CAPACITY):top(-1),CAPACITY(_CAPACITY)
{
    storage = new T[CAPACITY];
}
//destructor
template <class T>
DynamicArrayStack<T>::~DynamicArrayStack()
{
    delete[] storage;
}

//push to top of array, resizing if exceeding capacity
template <class T>
void DynamicArrayStack<T>::push(const T& item){
    
    if(top >= CAPACITY - 1){ // resize instead of exception
        //throw StackOverflowException();
        resize(CAPACITY*2);
    }
    storage[++top] = item; // increment top
}
//pop top value off, resizing if array is down to 1/4 of capacity
template <class T>
void DynamicArrayStack<T>::pop()
{
    T item = storage[--top]; // decrement top
    if(top > 0 && top == CAPACITY/4){ 
        resize(CAPACITY/2);
    }
} // don't traditional stacks return the pop'd value?
// return top value 
template <class T>
T DynamicArrayStack<T>::peek() const
{
    if(!isEmpty()){
        return storage[top];
    }else
        throw StackUnderflowException();

}
//return true if top index is out of bounds (-1)
template <class T>
bool DynamicArrayStack<T>::isEmpty() const
{
    return top == -1;
}

template <class T>
bool DynamicArrayStack<T>::isFull() const
{
    return false; // dynamically resized via resize()
}
//create a new array with internally passed resized capacity, copying all values over
template <class T>
void DynamicArrayStack<T>::resize(int nCAPACITY)
{
    T* temp = new T[nCAPACITY];
    for(int i = 0; i < CAPACITY; i++){
        temp[i] = storage[i];
    } 
    delete[] storage; // free up original array memory
    storage = temp;
    CAPACITY = nCAPACITY;
    cout << "nC: " << CAPACITY << endl;
}

#endif 
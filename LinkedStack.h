#ifndef LINKED_STACK
#define LINKED_STACK

#include "Stack.h"
#include <assert.h>
#include "StackOverflowException.h"
#include "StackUnderflowException.h"

#include "Node.h"
//Node struct didn't make me happy

template <class T>
class LinkedStack : public Stack<T>
{
    private:
        Node<T>* top;
        int count;

    public:
        LinkedStack();
        ~LinkedStack();
        void push(const T& data);
        void pop();
        T peek() const;
        bool isEmpty() const;
        bool isFull() const; // always return false due to expandability of LStack
};
//default constructor
template <class T>
LinkedStack<T>::LinkedStack() : top(nullptr), count(0)
{
}
//destructor - fundamentally, pulls each node off the top to delete
template <class T>
LinkedStack<T>::~LinkedStack(){
    Node<T>* a = top;
    while(a != NULL) {
        Node<T> *temp = a->getNext();
        delete a;
        a = temp;
    }
    count = 0;
}

template <class T>
void LinkedStack<T>::push(const T& data)
{
    Node<T>* psh = new Node<T>;
    psh->setItem(data);
    psh->setNext(top);
    top = psh;
    count ++;
}
//pop top node into a new temporary node, reassigning top to the next value;
template <class T>
void LinkedStack<T>::pop(){
    if(!isEmpty()){
        Node<T>* temp = top;
        top = top->getNext();
        delete temp;
        count --;
    } else{
        throw StackUnderflowException();
    }
}

template <class T>
T LinkedStack<T>::peek() const{
    if(!isEmpty()){
        return top->getItem();
    } else{
        throw StackUnderflowException();
    }
}

template <class T>
bool LinkedStack<T>::isEmpty() const{
    return count == 0;
}

template <class T>
bool LinkedStack<T>::isFull() const{
    return false;
}



#endif 
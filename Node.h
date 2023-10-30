#ifndef NODE_
#define NODE_

template<class T>
class Node
{
 private:
    T        item; // A data item
    Node<T>* next; // Pointer to next node
public:
    Node();
    Node(const T& anItem);
    Node(const T& anItem, Node<T>* nextNodePtr);
    void setItem(const T& anItem);
    void setNext(Node<T>* nextNodePtr);
    T getItem() const;
    Node<T>* getNext() const;
}; // end Node


template<class T>
Node<T>::Node() : item(NULL), next(nullptr)
{
}  // end default constructor
template<class T>
Node<T>::Node(const T& anItem) : item(anItem), next(nullptr)
{
}  // end constructor
template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr) 
                    : item(anItem), next(nextNodePtr)
{
}  // end constructor
template<class T>
void Node<T>::setItem(const T& anItem)
{
   item = anItem;
}  // end setItem
template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
   next = nextNodePtr;
}  // end setNext

template<class T>
T Node<T>::getItem() const
{
    return item;
}  // end getItem
template<class T>
Node<T>* Node<T>::getNext() const
{
   return next;
}

#endif
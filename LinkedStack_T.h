//
//  LinkedStack.h
//  Stacks
//
//  Created by Daniel Walsh on 4/8/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#ifndef __Stacks__LinkedStack_T__
#define __Stacks__LinkedStack_T__

#include <iostream>

template<typename T>
class Iterator_T {
public:
    virtual bool hasNext() = 0;
    virtual void remove() = 0;
    virtual T next() = 0;
};

template <typename T>
class LinkedStack_T
{
private:
    struct Node {
        T item;
        Node *next;
    };
    Node *first;
public:
    LinkedStack_T():first(NULL) {
        std::cout << "default const\n";
    }
    ~LinkedStack_T() {
        std::cout << "destructor\n";
        delete first;
    }
    inline bool isEmpty() { return first == NULL; }
    void push(T const item) {
        Node *oldfirst = first;
        first = new Node();
        first->item = item;
        first->next = oldfirst;
    }
    T pop() {
        T item = first->item;
        first = first->next;
        return item;
    }
    inline Node* getFirst() const { return first; }
private:
    template<typename U>
    class ListIterator_T : public Iterator_T<U> {
        Node *current;
        LinkedStack_T& parent;
    public:
        ListIterator_T(LinkedStack_T& p):parent(p),current(p.first) { }
        inline bool hasNext() { return current != NULL; }
        void remove() { }
        U next() {
            U item = current->item;
            current = current->next;
            return item;
        }
    };
public:
    inline ListIterator_T<T>* iterator(LinkedStack_T<T>& p) const { return new ListIterator_T<T>(p); }
};

#endif /* defined(__Stacks__LinkedStack_T__) */

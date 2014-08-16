//
//  ResizingArrayStackOfStrings.h
//  Stacks
//
//  Created by Daniel Walsh on 4/8/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#ifndef __Stacks__ResizingArrayStackOfStrings__
#define __Stacks__ResizingArrayStackOfStrings__

#include <iostream>

class ResizingArrayStackOfStrings
{
    std::string *s;
    int n;
    int capacity;
public:
    ResizingArrayStackOfStrings():n(0),capacity(1),s(new std::string[1]) {
        std::cout << "default const\n";
    }
    ~ResizingArrayStackOfStrings() {
        delete [] s;
        std::cout << "destructor\n";
    }
    inline bool isEmpty() { return n == 0; }
    void push(std::string item) {
        if (n == capacity) {
            resize(2 * capacity);
            std::cout << "resized\n";
        }
        s[n++] = item;
    }
    std::string pop() {
        std::string item = s[--n];
        s[n] = "";
        if (n > 0 && n == capacity/4) resize(capacity/2);
        return item;
    }
    void resize(int c) {
        std::string *copy = new std::string[c];
        for (int i = 0; i < n; ++i)
            copy[i] = s[i];
        s = copy;
    }
    inline const std::string& operator[](int index) const { return s[index]; }
};

#endif /* defined(__Stacks__ResizingArrayStackOfStrings__) */

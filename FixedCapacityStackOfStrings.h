//
//  FixedCapacityStackOfStrings.h
//  Stacks
//
//  Created by Daniel Walsh on 4/8/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#ifndef __Stacks__FixedCapacityStackOfStrings__
#define __Stacks__FixedCapacityStackOfStrings__

#include <iostream>

class FixedCapacityStackOfStrings
{
    std::string *s;
    int n;
public:
    FixedCapacityStackOfStrings(int capacity):s(new std::string[capacity]),n(0) {
        std::cout << "default const\n";
    }
    ~FixedCapacityStackOfStrings() {
        std::cout << "destructor\n";
    }
    inline bool isEmpty() { return n == 0; }
    inline void push(std::string item) { s[n++] = item; }
    inline std::string pop() { return s[--n]; }
};

#endif /* defined(__Stacks__FixedCapacityStackOfStrings__) */

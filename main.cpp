//
//  main.cpp
//  Stacks
//
//  Created by Daniel Walsh on 4/8/14.
//  Copyright (c) 2014 Daniel Walsh. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "LinkedStack_T.h"
#include "ResizingArrayStackOfStrings.h"

/****
 *
 * Each segment of code represents a separate test for the included
 * algorithms.  Simply uncomment a section set a breakpoint and run.
 *
 ****/

int main(int argc, const char * argv[])
{
    /****
     *
     * A simple (not so great) expression calculator. Only works
     * with '+' and '*'. Every term must be grouped with parenthesis.
     *
     * Example: (2*(4+3))  or (5+(3*6)+7)
     *
     ****/
    
    LinkedStack_T<char> ops;
    LinkedStack_T<double> vals;
    std::cout << "enter an expression:\n";
    std::string s;
    std::getline(std::cin, s);
    const char *ptr = s.c_str();
    for (const char *c = ptr; c < ptr + s.size(); ++c) {
        if (*c == '(') ;
        else if (*c == '+') ops.push(*c);
        else if (*c == '*') ops.push(*c);
        else if (*c == ')')
        {
            char op = ops.pop();
            if (op == '+') vals.push(vals.pop() + vals.pop());
            else if (op == '*') vals.push(vals.pop() * vals.pop());
        }
        else vals.push(std::atof(c));
    }
    std::cout << vals.pop() << '\n';

    /****
     *
     *  Basic test of the LinkedStack_T class.
     *  There is no user input.
     *
     ****
    
    LinkedStack_T<std::string> lsos;
    lsos.push("first");
    lsos.push("second");
    lsos.push("third");
    
    Iterator_T<std::string> *it = lsos.iterator(lsos);
    
    while (it->hasNext())
        std::cout << it->next() << '\n';
    
    LinkedStack_T<int> lsoi;
    lsoi.push(1);
    lsoi.push(2);
    lsoi.push(3);
    lsoi.push(4);
    
    Iterator_T<int> *it2 = lsoi.iterator(lsoi);
    
    while(it2->hasNext())
        std::cout << it2->next() << '\n';
    
    while (!lsos.isEmpty())
        std::cout << lsos.pop() << '\n';
    
    /****
     *
     *  Basic test of the ResizingArayStackOfStrings class.
     *  There is no user input.
     *
     ****
    
    ResizingArrayStackOfStrings rasos;
    rasos.push("first");
    rasos.push("second");
    rasos.push("third");
    rasos.push("fourth");
    rasos.push("fifth");

    while (!rasos.isEmpty())
        std::cout << rasos.pop() << '\n';
    
    /**/
    
    return EXIT_SUCCESS;
}


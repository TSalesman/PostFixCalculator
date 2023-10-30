#ifndef INVALID_POSTFIX
#define INVALID_POSTFIX

#include <iostream>

using namespace std;

class InvalidpostfixExpression: public exception{
    public:
        const char* what() const throw ()
        {
            return "Invalid postfix expression";
        }

};

#endif
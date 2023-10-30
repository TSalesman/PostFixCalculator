#ifndef POSTFIX_EXPRESSION_CALCULATOR
#define POSTFIX_EXPRESSION_CALCULATOR

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "Stack.h"
#include "InvalidpostfixExpression.h"

// all possible math operations, % excluded due to only double operations.
static char OPERATORS[4] = {'+', '-', '*', '/'}; 

class PostfixExpressionCalculator
{
    private:
        //stores values mid operations
        Stack<double>& storage; 
    public:
        PostfixExpressionCalculator(Stack<double>& stack);
        // provides solution to expression
        double evaluate(string postfixExpression);
        // returns whether c is a operator
        bool operatorCheck(char _c); 
        // performs math operations based on operator _o
        double resolve(double _a, double _b, char _o); //
};

PostfixExpressionCalculator::PostfixExpressionCalculator(Stack<double>& stack) : storage(stack)
{
}

double PostfixExpressionCalculator::evaluate(string postfixExpression)
{
    int count = 0; // # of values in stack
    int resolved = 0; // # of previously operated on values
    int length = postfixExpression.length();
    int subindex = 1; // Iterator; using for-each
    for(char& c : postfixExpression){
        if(operatorCheck(c)){
            if((count + resolved < 2)||(c == '/' && storage.peek() == 0)) // operation on fewer than 2 operands or dividing by 0
                    throw InvalidpostfixExpression();
            cout << count << " :: " << c << endl;
            double current = storage.peek();
            storage.pop();
            count--;

            if(resolved == 1 && (subindex < postfixExpression.length())){
                while(count + 1 > resolved){
                    current = resolve(storage.peek(), current, c);
                    storage.pop();
                    count--; 
                }
            }else{
                while(!storage.isEmpty()){
                    current = resolve(storage.peek(), current, c);
                    storage.pop();
                    count--; 
                }
            }
            storage.push(current);
            resolved++;
        }else{
            storage.push(double(c - 48));
            count++;
        }
        subindex++;
    }
    double result = storage.peek();
    storage.pop();
    return result;
}

// returns whether _c is a operator
bool PostfixExpressionCalculator::operatorCheck(char _c)
{
    for(char o : OPERATORS){
        if(_c == o){
            return true;
        }
    }
    return false;
}

// performs math operations based on operator _o
double PostfixExpressionCalculator::resolve(double _a, double _b, char _o)
{ //OPERATORS [] : {'+', '-', '*', '/'};
    if(_o == OPERATORS[0]){ // + 
        return _a + _b;
    }else if(_o == OPERATORS[1]){ //  - 
        return _a - _b;
    }else if(_o == OPERATORS[2]){ //  *  
        return _a * _b;
    }else if(_o == OPERATORS[3]){ //  / 
        return _a / _b;
    }
    return 0.0;
}


#endif 
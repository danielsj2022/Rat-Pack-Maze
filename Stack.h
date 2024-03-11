#ifndef COP4530_Stack_H
#define COP4530_Stack_H

#include <iostream>
#include <vector>
//using namespace std;
namespace cop4530 {

template <typename T>
class Stack{
 public:
   Stack();   //default
   ~Stack();   //destructor
   Stack(const Stack &rhs);  //copy constructor
   Stack(Stack &&rhs);   // move constructor
   Stack& operator=(const Stack &rhs);   // copy assignment operator
   Stack& operator=(Stack &&rhs);   // move assignment operator
   bool empty() const;
   T& top();    //return a reference to the top
   const T& top() const;  // constant version
   void pop();  // remove the first element
   void push(const T& val);  // push a new element val 
   void push(T&& val);  // add a new element val to the stack. val should be moved
   int size() const;  // return the number of elements

 protected:
   std::vector<T> v;
};

#include "Stack.hpp"
}   //end of name cop
#endif

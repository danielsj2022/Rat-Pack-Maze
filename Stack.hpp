#include <iostream>
#include <cstdlib>
using namespace std;
//namepsace cop4530;

template <typename T>
cop4530::Stack<T>::~Stack()
{
}
template <typename T>
cop4530::Stack<T>::Stack()
{
   v.clear(); 
} 
template <typename T>
cop4530::Stack<T>::Stack(const Stack &rhs)  //copy constructor
{
   v=rhs.v;
}
template <typename T>
cop4530::Stack<T>::Stack(Stack &&rhs)   // move constructor
{
   v=rhs.v;
   rhs.v.clear();   
}
template <typename T>
cop4530::Stack<T>& cop4530::Stack<T>::operator=(const Stack &rhs)   // copy assignment operator
{
   if(this!=&rhs)
   {
      v.clear();
      v=rhs.v;
   }   
   return *this;
}
template <typename T>
cop4530::Stack<T>& cop4530::Stack<T>::operator=(Stack &&rhs)   // move assignment operator
{
   if(this!=&rhs)
   {
      v.clear();
     /* for(int i=0; i<rhs.size(); i++)
      {
	 v[i]=rhs.v[i];
      }
     */
      v=rhs.v;
      rhs.v.clear();
   }
   return *this;

}
template <typename T>
int cop4530::Stack<T>::size() const
{
   return v.size();
}
template <typename T>
bool cop4530::Stack<T>::empty() const
{
   if(v.empty())
      return true;
   else
      return false;
}
template <typename T>
T& cop4530::Stack<T>::top()    //return a reference to the top
{
   return v.front();
}

template <typename T>
const T& cop4530::Stack<T>::top() const  // constant version
{
   return v.front();
}
template <typename T>
void cop4530::Stack<T>::pop()  // remove the first element
{
   v.erase(v.begin());
}
template<typename T>
void cop4530::Stack<T>::push(const T& val)  // push a new element val
{
   v.insert(v.begin(), val);
}
template <typename T>
void cop4530::Stack<T>::push(T&& val)  // add a new element val to the stack. val should be moved
{
   v.insert(v.begin(), val);
   val=0;
}


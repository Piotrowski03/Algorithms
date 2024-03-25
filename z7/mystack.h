#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "arraylist.h"
template <typename T>
class MyStack {
    ArrayList<T> lst;
public:
    MyStack(int s=10) {// default constructor
     lst.msize = s;
     lst.last=0;
     assert(s>0);
     lst.tab = new T[s];
     assert(lst.tab  != nullptr);
} 
    ~MyStack() { lst.clear(); }
    
    MyStack(const MyStack& other){// copy constructor
    lst.msize= other.lst.msize;
    lst.last=other.lst.last;
    lst.tab = new T[lst.msize];
    for(int i = 0 ; i<lst.last;i++){
    	lst.tab[i] = other.lst.tab[i];
    }
}
    
    MyStack& operator=(const MyStack& other){// copy assignment operator, return *this
    lst.clear();
    lst.msize=other.lst.msize;
    lst.last=other.lst.last;
    lst.tab = new T[lst.msize];
    for(int i = 0 ; i<lst.last;i++){
    	lst.tab[i] = other.lst.tab[i];
    }
    return *this;
}
    
    bool empty() const { return lst.empty(); } // checks if the container has no elements
    bool full() const { return lst.full(); }
    int size() const { return lst.size(); }
    int max_size() const { return lst.max_size(); }
    void push(const T& item) { lst.push_back(item); }
    T& top() { return lst.back(); } // zwraca koniec, nie usuwa
    void pop() { lst.pop_back(); } // usuwa koniec
    void clear() { lst.clear(); }
    void display(){lst.display();}
};
#endif

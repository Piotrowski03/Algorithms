#include <iostream>
#include "arraylist.h"
#include "mystack.h"
int main() {
    MyStack<int> myList;
    myList.push(1);
    myList.push(5);
    myList.push(7);
    myList.push(4);
    myList.push(3);
    myList.push(2);
    
    //copy assignment operator test
    MyStack<int> nextlist;
    nextlist = myList;
    std::cout<<"copy assignment operator test"<<std::endl;
    myList.display();
    nextlist.display();
    
    //copy constructor test
    MyStack<int> List(myList);
    std::cout<<"copy constructor test"<<std::endl;
    std::cout<<"expected results: ";
    myList.display();
    List.display();
    
    //top test
    std::cout<<"top test"<<std::endl;
    std::cout<<myList.top()<<std::endl;
    //pop test
    std::cout<<"pop test"<<std::endl;
    myList.pop();
    myList.display();
    
    //size test
    int size = myList.size();
    std::cout<<"size test"<<std::endl;
    std::cout<<"expected value is 5"<<std::endl;
    std::cout<<size<<std::endl;
    
    
    
    //clear test
    std::cout<<"clear test"<<std::endl;
    myList.clear();
    if(myList.empty()){
    std::cout<<"stos jest pusty"<<std::endl;
    }
    else{
    std::cout<<"stos nie jest pusty"<<std::endl;
    }
    
   
    return 0;
    
    
}

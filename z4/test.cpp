#include <iostream>
#include "setArr.h"
int main() {
    SingleList<int> myList;
    myList.push_front(1);
    myList.push_front(5);
    myList.push_front(7);
    myList.push_front(4);
    myList.push_front(3);
    myList.push_front(2);
    
    //copy assignment operator test
    SingleList<int> nextlist;
    nextlist = myList;
    std::cout<<"copy assignment operator test"<<std::endl;
    myList.display();
    nextlist.display();
    
    //copy constructor test
    SingleList<int> List(myList);
    std::cout<<"copy constructor test"<<std::endl;
    std::cout<<"expected results: ";
    myList.display();
    List.display();
    
    //size test
    int size = myList.size();
    std::cout<<"size test"<<std::endl;
    std::cout<<"expected value is 6"<<std::endl;
    std::cout<<size<<std::endl;
    
    //reverse test
    std::cout<<"reverse test"<<std::endl;
    std::cout<<"expected outcome is: 1 5 7 4 3 2"<<std::endl;
    myList.reverse();
    myList.display();
    
    
    //clear test
    std::cout<<"clear test"<<std::endl;
    myList.clear();
    if(myList.empty()){
    std::cout<<"Lista jest pusta"<<std::endl;
    }
    else{
    std::cout<<"lista nie jest pusta"<<std::endl;
    }
    
   
    return 0;
    
    
}

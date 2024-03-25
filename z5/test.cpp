#include <iostream>
#include "doublelist.h"

int main(){
DoubleList<int> myList;

myList.push_front(3);
myList.push_front(5);
myList.push_front(2);
myList.push_front(7);
myList.push_front(1);
myList.push_front(9);
myList.push_front(8);
myList.push_front(0);

//display and display reversed test
std::cout<<"display and display reversed test"<<std::endl;
myList.display();
myList.display_reversed();
//copy assignment operator test
std::cout<<"copy assignment operator test"<<std::endl;
DoubleList<int> list1;
list1=myList;
myList.display();
list1.display();

//copy constructor test
std::cout<<"copy contructor test"<<std::endl;
DoubleList<int> list2(myList);
myList.display();
list2.display();

//size test
std::cout<<"size test"<<std::endl;
int i = myList.size();
std::cout<<"expected value is 8 actual value : "<<i<<std::endl;

//pushback test
list1.push_back(4);
std::cout<<"push_back test the number pushed back is 4"<<std::endl;
list1.display();

//pop_back test
list1.pop_back();
std::cout<<"pop_back test, popped value is 4"<<std::endl;
list1.display();

//pop_front test
list2.pop_front();
std::cout<<"pop_front test, popped value is 0"<<std::endl;
list2.display();

//clear test
list2.clear();
std::cout<<"clear method test"<<std::endl;
if(list2.empty()==1){
std::cout<<"list is empty"<<std::endl;
}



return 0;
}

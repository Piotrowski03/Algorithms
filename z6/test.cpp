#include <iostream>
#include "mydeque.h"

int main(){

MyDeque<int> queue;

queue.push_front(3);
queue.push_front(2);
queue.push_front(1);
queue.push_front(6);
queue.push_front(7);
queue.push_front(9);

//copy constructor test
MyDeque<int> test1(queue);
std::cout<<"copy constructor test"<<std::endl;
queue.display();
test1.display();

//copy assignment operator test
MyDeque<int> test2 = test1;
std::cout<<"copy assignment operator test"<<std::endl;
queue.display();
test2.display();

//pop front test
std::cout<<"pop front test, popped integer is 3"<<std::endl;
queue.pop_front();
queue.display();

//pop back test
std::cout<<"pop back test, popped integer is 9"<<std::endl;
queue.pop_back();
queue.display();

//clear test
std::cout<<"clear test"<<std::endl;
queue.clear();
if(queue.empty()){
std::cout<<"the deque is empty"<<std::endl;
}
return 0;
}

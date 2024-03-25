//do kompilacji i uruchomienia make run1

#include <iostream>
#include "arraylist.h"
int main() {
    ArrayList<int> list(9);
    
    //test push_front
    list.push_front(5);
    list.push_front(8);
    list.push_front(12);
    list.push_front(35);
    list.push_front(6);
    list.push_front(9);
    list.push_front(21);
    list.push_front(66);
    list.push_front(1);

cout<<"push_front test -lista powinna wygladac nastepujaco : [1, 66, 21, 9, 6, 35, 12, 8, 5]: "<<list<<endl;

	//test pop_front
	list.pop_front();
cout<<"pop_front test - lista powinna wygladac nastepujaco : [66, 21, 9, 6, 35, 12, 8, 5]: "<<list<<endl;

	//test push_back
	list.push_back(13);
cout<<"pop_front test - lista powinna wygladac nastepujaco : [66, 21, 9, 6, 35, 12, 8, 5, 13]: "<<list<<endl;

	//test pop_back
	list.pop_back();
cout<<"pop_back test -  lista powinna wygladac nastepujaco : [66, 21, 9, 6, 35, 12, 8, 5]: "<<list<<endl;

	//test front
cout<<"test front - liczba 66: "<<list.front()<<endl;

	//test back
cout<<"test back - liczba 5: "<<list.back()<<endl;

	//test sort
	list.sort();
cout<<"sort test - lista powinna wygladac nastepujaco : [5, 6, 8, 9, 12, 21, 35, 66]: "<<list<<endl;

	//test reverse
	list.reverse();
cout<<"reverse test - lista powinna wygladac nastepujaco : [66, 35, 21, 12, 9, 8, 6, 5 ]:"<<list<<endl;

	//test clear
	list.clear();
cout<<"clear test -"<<list<<endl;
return 0;
}
	
	
	
	


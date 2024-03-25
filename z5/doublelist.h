// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    
template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(){
     while(head!=nullptr ) {
     	DoubleNode<T> *node=head;
        head = head->next; 
        delete node;   
    	}
}// tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other){ // copy constructor
    if(other.head!=nullptr){
   	 head=new DoubleNode<T>(other.head->value);
   	 tail=head;
   	 DoubleNode<T> *currentother = other.head->next;
    	while(currentother!=nullptr){
    		DoubleNode<T>* Node = new DoubleNode<T>(currentother->value);
    		tail->next= Node;
    		Node->prev= tail;
    		tail= tail->next;
    		currentother=currentother->next;
    		}
    	}
}
    		
    // usage:   DoubleList<int> list2(list1);

    DoubleList& operator=(const DoubleList& other){ // copy assignment operator, return *this
    clear();
    DoubleNode<T> *currentother =other.head;
    while(currentother!=nullptr){
    	if(head==nullptr){
    		head = currentother;
   		tail=currentother;
   		}
   	else{
    		DoubleNode<T>* newnode = new DoubleNode<T>(currentother->value);
    		tail->next=newnode;
    		newnode->prev=tail;
    		tail=newnode;
    		}
    		currentother=currentother->next;
    	}
    	//other.clear();
    return *this;
}
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    
    int size() const{ // O(n) bo trzeba policzyc
    int i=0;
   	 DoubleNode<T>* iterator = head;
    	while(iterator!=nullptr){
   		iterator= iterator->next;
  		 i++;
  	 }
   return i;
   }
    void push_front(const T& item);// O(1)  
    
    void push_front(T&& item); // O(1) NIEOBOWIAZKOWE
      
      void push_back(const T& item){ // O(1)
    if (!empty()) {
        tail->next = new DoubleNode<T>(item, nullptr, tail);
        tail = tail->next;
        tail->prev->next=tail;
    } 
    else {
        head = tail = new DoubleNode<T>(item);
    }
}
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    
    void pop_front(){ // usuwa poczatek O(1)
    assert(!empty());
    DoubleNode<T> *todelete = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete todelete;
    }
}

    void pop_back(){// usuwa koniec O(1)
    assert(!empty());
    DoubleNode<T>* todelete = tail;
    if(head==tail){
    	head=tail=nullptr;
    	}
    else{
    	tail=tail->prev;
    	tail->next=nullptr;
    	delete todelete;
    	}
}
    void clear(){ // czyszczenie listy z elementow O(n)
    while(!empty()){
    pop_front();
    }
}   
    void display(){ // O(n)
    DoubleNode<T> *iterator = head;
    while(iterator!= nullptr){
    	std::cout<<iterator->value<<" ";
    	iterator=iterator->next;
    	}
    std::cout<<std::endl;
    }
    
    void display_reversed(){// O(n)
    DoubleNode<T> *iterator = tail;
    while(iterator!=nullptr){
    	std::cout<<iterator->value<<" ";    
    	iterator=iterator->prev;
    	}
    std::cout<<std::endl;
}

};

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head->prev= new DoubleNode<T>(item, head,nullptr);
        head=head->prev;
    } else {
        head = tail = new DoubleNode<T>(item);
        
    }
}
template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}

#endif

// EOF

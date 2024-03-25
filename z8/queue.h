#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class MyQueue {
   SingleNode<T> *head, *tail; // zależne od implementacji
public:
    MyQueue(): head(nullptr), tail(nullptr) {}
    ~MyQueue(){ clear();}
    MyQueue(const MyQueue& other){ // copy constructor
    head=nullptr;;
    tail=nullptr;
    if (other.head != nullptr) {
        head = new SingleNode<T>(other.head->value);
        tail = head;

        SingleNode<T>* currentOther = other.head->next;
        while (currentOther != nullptr) {
            tail->next = new SingleNode<T>(currentOther->value);
            tail = tail->next;
            currentOther = currentOther->next;
        }
    }
}

    MyQueue(MyQueue&& other){ // move constructor
    tail = other.tail;
    head=other.head;
    other.head = other.tail = nullptr;
}
    MyQueue& operator=(const MyQueue& other){ // copy assignment operator, return *this
    clear();
    SingleNode<T>* currentother = other.head;
    while(currentother!= nullptr){
   	SingleNode<T> *newnode = currentother;
    	if(head==nullptr){
    		head = newnode;
    		tail = newnode;
    		}
    	else{
    		tail->next=newnode;
    		tail= newnode;
    		}
    	currentother=currentother->next;
    }
    return *this;
}
    MyQueue& operator=(MyQueue&& other){ // move assignment operator, return *this
    clear();
     if (this != &other) { // Sprawdzenie, czy nie przypisujemy samego sobie
        // Wyczyszczenie obecnych zasobów
        clear();

        // Przeniesienie zasobów z innej kolejki
        head = other.head;
        tail = other.tail;

        // Resetowanie zasobów oryginalnej kolejki
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}
    bool empty() const{return head == nullptr;} // checks if the container has no elements
    int size() const{ // liczba elementów w kolejce
    int i=0;
   	 SingleNode<T>* iterator = head;
    	while(iterator!=nullptr){
   		iterator= iterator->next;
  		 i++;
  	 }
   return i;
}

    void push(const T& item){ // dodanie na koniec, push_back(item)
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

    void push(T&& item){// dodanie na koniec, push_back(std::move(item))
    if (!empty()) {
        tail->next = new SingleNode<T>(std::move(item));
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(std::move(item));
    }
}
    
    T& front(){return head->value;} // zwraca koniec, nie usuwa
    
    T& back(){return tail->value;} // zwraca koniec, nie usuwa
    void pop(){// usuwa początek kolejki, pop_front()
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}
    void clear(){// czyszczenie listy z elementów
    SingleNode<T> *node = head;
    while (node != nullptr){
        SingleNode<T> *delnode = node;
        node = node->next;
        delete delnode;
    }
    head=tail=nullptr;
}
    void display(){
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}
};
#endif

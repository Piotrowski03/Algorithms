// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

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
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();
    SingleList(const SingleList& other){ // copy constructor
    head=nullptr;
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


    SingleList& operator=(const SingleList& other){ // copy assignment operator, return *this
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
    // usage:   list2 = list1;


    bool empty() const { return head == nullptr; }
    
    int size() const{ // O(n) bo trzeba policzyc-
    	int i=0;
   	 SingleNode<T>* iterator = head;
    	while(iterator!=nullptr){
   		iterator= iterator->next;
  		 i++;
  	 }
   return i;
   }
   
    void push_front (const T& item); // O(1), L.push_front(item)
    
    void push_back(const T& item);// O(1), L.push_back(item)
    
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    
    void pop_front ();// usuwa poczatek O(1)
    
    void pop_back(); // usuwa koniec O(n)
    
    void clear(){// czyszczenie listy z elementow O(n)-
     while(!empty()){
     pop_front();
    }
    head = tail = nullptr;
    
}
    void display();

    void reverse(){ // O(n)-
    SingleNode<T>* previous = nullptr;
    SingleNode<T>* current = head;
    SingleNode<T>* nextnode = nullptr;
    while (current != nullptr) {
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    head = previous;
    tail = head; 
}
    

};

template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

#endif

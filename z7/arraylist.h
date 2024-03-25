// arraylist.h
using namespace std;
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <cstdlib>

template <typename T>
class ArrayList {
public:
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja

    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    
    ~ArrayList() { delete [] tab; } // destruktor

    ArrayList(const ArrayList& other){
    	tab = new T[msize];
    	for(int m=0; m < last; m++){
			tab[m] = other.tab[m];
		}// copy constructor
    }// usage:   ArrayList<int> list2(list1);

    ArrayList& operator=(const ArrayList& other){
      	if(this != &other) {
    		delete [] tab;
		msize = other.msize;
		last = other.last;
		tab = new T[msize];
		for(int i=0; i < last; i++){
			tab[i] = other.tab[i];
		}
	return *this;
	}
    }  // copy assignment operator, return *this
    // usage:   list2 = list1;



    bool empty() const { return last == 0; } // checks if the container has no elements
    
    bool full() const { return last == msize; } // checks if the container is full
    
    int size() const { return last; } // liczba elementow na liscie
    
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow
    
    void push_front(const T& item){// dodanie na poczatek
    if(full()){
    cout<<"this container is full"<<endl;
    }
    else{
   	 for(int i= last;i>0;i--){
    		tab[i] = tab[i-1];
    		}
    	 tab[0] = item;
    	 last++;
    	 }
    }    
    
    void push_back(const T& item) {// dodanie na koniec
    if(full()){
    cout<<"this container is full"<<endl;
    }
    else{
    	tab[last] = item;
    	last++;
    	}
    }	
    
    T& front(){// zwraca poczatek, nie usuwa, error dla pustej listy
    assert(this->empty() == 0);
    return tab[0];
    }
    
    T& back(){//zwraca koniec, nie usuwa, error dla pustej listy
    assert(this->empty() ==0);
    return tab[last-1];
    }
    
    void pop_front(){ // usuwa poczatek, error dla pustej listy
    assert(this->empty()==0);
    	for(int i=0;i<last;i++){
    	tab[i]=tab[i+1];
    	}
    last--;
    }
    
    void pop_back(){// usuwa koniec, error dla pustej listy
    assert(this->empty()==0);
    last--;
    }
    
    void clear(){// czyszczenie listy z elementow
    	for(int i =0; i<=last;i++){
    	tab[i]= T();
    	}
    	last=0;
    }
    
    void display(){ // lepiej zdefiniowac operator<<
    	for(int i=0;i<last;i++){
    		cout<<tab[i]<<" ";
    		}
    		cout<<endl;
    }
    void reverse(){ // odwracanie kolejnosci
    int b = last;
    	for(int i=0;i<last/2;i++){
    		int a = tab[i];
    		tab[i]=tab[b-1];
    		tab[b-1]=a;
    		b--;
		}
	}
	
    void sort(){// sortowanie listy
    	for(int i=last-2;i>=0;i--){
    		for(int j=0;j<=i;j++){
    			if(tab[j]>tab[j+1]){
    			swap(tab[j],tab[j+1]);
    			}
    		}
   	 }
     }

    
    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF

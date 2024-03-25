
#include <iostream>
#
using namespace std;
template <typename T>
void quicksort(T *tab, int left, int right){
    if(left<right){
        T pivot = tab[right];
        int i =left;
        for(int j = left;j<right;j++){
            if(tab[j]<pivot){
                swap(tab[j],tab[i]);
                i++;
            }
        }
        swap(tab[i],tab[right]);
        quicksort(tab,left,i-1);
        quicksort(tab,i+1,right);
    }
    else{return;};
}

template <typename T>
void sprawdzenie(T *tab, int size){
 bool check = 1;
  for(int k= 1;k<size;k++){
  if(tab[k-1]>tab[k]){
  	check = 0;
  	}
  }
  if(check == 0){
  	cout<<"tablica zostala zle posortowana\n";
  	}
  }
    int main(){
        int tab[] = {5, 7, 9, 12, 13, 6, 45, 65};
        int size = sizeof(tab) / sizeof(tab[0]);
        quicksort(tab, 0, size-1);
        sprawdzenie(tab, size-1);
        for(int i=0; i<size ;i++){
            cout<<tab[i]<<" ";
        }
    }
    
    
    


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void sortowanie(int tablica[], int n){
 for(int i =0;i<=n;i++){
   for(int j = 1;j<=n-i-1;j++){
     if(tablica[j]<tablica[j-1]){
       swap(tablica[j], tablica[j-1]);
     }
       
   }
 }

}
void sprawdzenie(int tablica[], int n){
 bool check = 1;
  for(int k= 1;k<n;k++){
  if(tablica[k-1]>tablica[k]){
  	check = 0;
  	}
  }
  if(check == 1){
  	cout<<"tablica zostala poprawnie posortowana\n";
  	}
  else{
  	cout<<"tablica zostala zle posortowana\n";
  	}
  }

int main(){
  int tablica [] = {1, 5, 7, 8 , 9, 6 , 4};
  int n = sizeof(tablica) / sizeof(tablica[0]) ;
  sortowanie(tablica, n); //posortowanie tablicy
  sprawdzenie(tablica, n); //sprawdzenie czy zostala poprawnie posortowana
for(int i = 0; i<n;i++){
  cout<<tablica[i]<<" ";
}
cout<<"\n";
}

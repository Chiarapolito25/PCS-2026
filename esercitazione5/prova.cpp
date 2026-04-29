#include <iostream>
#include "merge_and_quick.hpp"
#include <vector>

using namespace std;

int main(){
	int n;
	cout<<"inserisci la dimensione del vettore da ordinare: ";
	cin >> n;
	vector<int> v(n);
	
	for (int i=0; i<n; i++){
		cout << "inserisci la componente "<< i <<" -esima : ";
		cin >> v[i];
	}
	
	vector<int> v1=v;
	vector<int> v2=v;
	vector<int> v3=v;
	
	//merge_sort
	merge_sort(v1, 0, n-1);
	cout<<"utilizzando merge_sort: [";
	for (int i=0; i<n-1; i++){
		cout<< v1[i]<< " , ";
	}
	cout<< v1[n-1] << " ]\n ";
	
	//quicksort
	quick_sort(v2, 0, n-1);
	cout<<"utilizzando quick_sort: [";
	for (int i=0; i<n-1; i++){
		cout<< v2[i]<< " , ";
	}
	cout<< v2[n-1] << " ]\n ";
	
	//quicksort ottimizzato 
	quick_sort_ottimizzato(v3, 0, n-1);
	cout<<"utilizzando quick_sort_ottimizzato: [";
	for (int i=0; i<n-1; i++){
		cout<< v3[i]<< " , ";
	}
	cout<< v3[n-1] << " ]\n ";
	return 0;
}
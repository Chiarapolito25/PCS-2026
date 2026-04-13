#include <iostream>
#include "sort_algorithms.hpp"
#include <vector>

using namespace std;

int main(){
	int n;
	vector<int> v;
	cout<<"inserisci la dimensione del vettore da ordinare: ";
	cin >> n;
	
	v.resize(n);
	
	for (int i=0; i<n; i++){
		cout << "inserisci la componente "<< i <<" -esima : ";
		cin >> v[i];
	}
	
	vector<int> v1,v2,v3;
	v1=v;
	v2=v;
	v3=v;
	
	//lubblesort
	bubble_sort(v1);
	cout<<"utilizzando bubble_sort: [";
	for (int i=0; i<n-1; i++){
		cout<< v1[i]<< " , ";
	}
	cout<< v1[n-1] << " ]\n ";

	//insertionsort
	insertion_sort(v2);
	cout<<"utilizzando insertion_sort: [";
	for (int i=0; i<n-1; i++){
		cout<< v2[i]<< " , ";
	}
	cout<< v2[n-1] << " ]\n ";
	
	//selection sort
	selection_sort(v3);
	cout<<"utilizzando selection_sort: [";
	for (int i=0; i<n-1; i++){
		cout<< v3[i]<< " , ";
	}
	cout<< v3[n-1] << " ]\n ";
	
	return 0;
}
#pragma once //Se hai già letto questo file, ignoralo per il resto di questa sessione
#include <vector>
#include <algorithm> //questa libreria contiene funzioni già pronte per manipolare i dati, per es. swap, max,min...
#include <optional>

template<typename T>

//verifico se un vettore è già ordinato

bool is_sorted(const std::vector<T>& A){
	int n=A.size();
	
	if (n<=1){
		return true;
	}
	
	for (int i=0; i<n-1; i++){
		if (A[i]>A[i+1]){
			return false;
		}
	}
	
	return true;
	
}	
	

// 1 Bubble Sort
template<typename T>
void bubble_sort(std::vector<T>& A) {
	int n=A.size();
	if (is_sorted(A)) { 
        return; 
    }
	
	for (int i=0; i<n-1; i++){
		for (int j=n-1;j>=i+1;j-=1){
			if (A[j]<A[j-1]){
				std::swap(A[j], A[j-1]);
			}
		}
	}
	
}


// 2. Insertion Sort
template<typename T>
void insertion_sort(std::vector<T>& A) {
	int n=A.size();
	if (is_sorted(A)) { 
        return; 
    }
	
	for (int i=1; i<=n-1; i++){
		T value = A[i];
		int j=i-1;
		while (j>=0 && A[j]>value){
			std::swap(A[j+1], A[j]);
			j=j-1;
			}
		A[j+1]=value;
	}

}

// 3. Selection Sort
template<typename T>
void selection_sort(std::vector<T>& A) {
	int n=A.size();
	if (is_sorted(A)) { 
        return; 
    }
	
	for (int i=0; i<n-1; i++){
		int min_index= i;
		for (int j=i+1; j<=n-1; j++){
			if (A[j]<A[min_index]){
				min_index=j;
			}
		}
		if ( min_index!=i){
			std::swap(A[i], A[min_index]);
		}
	}
	
}
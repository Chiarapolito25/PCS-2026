#pragma once //Se hai già letto questo file, ignoralo per il resto di questa sessione
#include <vector>
#include <algorithm> //questa libreria contiene funzioni già pronte per manipolare i dati, per es. swap, max,min...
#include <optional>
#include <cmath>
#include "sort_algorithms.hpp"


using namespace std;

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

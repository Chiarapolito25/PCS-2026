#pragma once //Se hai già letto questo file, ignoralo per il resto di questa sessione
#include <vector>
#include <algorithm> //questa libreria contiene funzioni già pronte per manipolare i dati, per es. swap, max,min...
#include <optional>
#include <cmath>
#include "sort_algorithms.hpp"
#include "is_sorted.hpp"


using namespace std;

// Partition
template<typename T>
int Partition(vector<T>& A,int s,int p, int d) {
	if (p!=d){
		swap(A[p],A[d]);
		p=d;
	}
	int i=s-1;
	for (int j=s; j<=d-1; j++){
		if (A[j]<=A[p]){
			i=i+1;
			swap(A[i],A[j]);
		}
	}
	if (i!=d){
		swap(A[i+1],A[p]);
	}
	return i+1; //rango
	
}


//fusion (chiamata anche merge, fusion è la notazione utilizzata a lezione)
//Il merge prende due pezzi del vettore A alla volta e li fonde;
template<typename T>
void fusion(vector<T>& A,int s, int c, int d) {
	//c sta per centro
	
	int n1=c-s+1; //lunghezza della parte sinistra, dall'inizio s al punto medio (incluso) c
	int n2=d-c; //lunghezza da c+1 a d (inclusi)
	
	vector<T> L(n1);
	vector<T> R(n2);
	//aggiungiamo +1 perchè poi l'ultimo valore sarà la sentinella, infinito
	
	for (int i=0;i<n1; i++){
		L[i]=A[s+i]; //se s è l'inizio del blocco, il primo indice è s+0
	}
	// ovvero L contiene A[0:c-1], basta che sostiuisco i=c-s+1-1=c-s 
	for (int j=0;j<n2; j++){
		R[j]=A[c+j+1]; //dobbiamo sommare +1 perchè non dobbiamo includere il punto medio 
	}
	
	// A è ordinato, quindi le due sottometà di A,L e R, sono ordinate
	
	
	// ovvero R contiene A[c+1:c-1], basta che sostituisco j=d-c-1
	//creo due array temporanei L=left, R=right
	int i=0; //indice per L
	int j=0; //indice per R
	int k=s;
	//confronto i due vettori per ogni k, in modo che piazzo in A la componente più piccola tra L e R
	//k aumenta in ogni caso, mentre i aumenta se il più piccolo e in L, j aumenta se il più piccolo è in R (scorro L e R man mano)
	while (i < n1 && j < n2){
		if (L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
	while (j < n2) {//se j=size(vettoreR) ho finito di esplorare e copio le altre
		A[k] = R[j];
        j++;
        k++;
    }

}
	
	
// 1 Merge Sort
template<typename T>
void merge_sort(vector<T>& A,int s, int d) {
	if(s<d){
		int centro=(s+d)/2;
		//Se s e d sono interi, (s+d)/2 esegue già una
		// divisione intera (troncata), quindi floor è superfluo
		merge_sort(A,s,centro);
		merge_sort(A,centro+1,d);
		fusion(A,s,centro,d);
	}
	
}

// 1 Quick Sort
template<typename T>
void quick_sort(vector<T>& A,int s, int d) {
	
	if(s<d){
		int p=s+rand()%(d-s+1);
		int r=Partition(A,s,p,d);
		quick_sort(A,s,r-1);
		quick_sort(A,r+1,d);
	}
}
	
//quick_sort_ottimizzato
template<typename T>
void quick_sort_ottimizzato(vector<T>& A,int s, int d) {
	int n=d-s+1; //se ho il vettore iniziale, d corrisponde a n-1, ma la dimensione del vettore è n
	
	if (s >= d) {
		return;
	}
	vector<T> A_temp(n); 
	
	int soglia=32;
	if (n<=soglia){

		// Copio da A[s...d] a A_temp[0...n-1]
		for (int k = 0; k < n; k++) {
			A_temp[k] = A[s + k];
		}

		// Ordino il vettore temporaneo
		insertion_sort(A_temp);

		//Ricopio da A_temp[0...n-1] a A[s...d]
		for (int k = 0; k < n; k++) {
			A[s + k] = A_temp[k];
		}
	}	
	else{
		int p=s+rand()%(d-s+1); //elemento pivot
		int r=Partition(A,s,p,d);
		quick_sort_ottimizzato(A,s,r-1);
		quick_sort_ottimizzato(A,r+1,d);
	}

}
	
	
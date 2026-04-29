#include <iostream>
#include <vector>
#include <string>
#include "sort_algorithms.hpp"
#include "randfiller.h"
#include <random>
using namespace std;

int main(void){
	random_device rd;
	randfiller rf;
	
	for (int i=0; i<100; i++){
		int n=rd()%100;
		vector<int> vi;
		vi.resize(n);
		rf.fill(vi,-100,100);
		bubble_sort(vi);
		if (is_sorted(vi)){}//il codice ha funzionato 
		//sui numeri, quindi controllo sulle stringhe
		else{
			return EXIT_FAILURE; //ritornerà qualsiasi altro numero diverso da 0, ma sarà un numero / (int main...) 
		}
	}

	vector<string> v={"Mela", "Computer", "Orizzonte", "Lampada", "Gatto", 
	"Montagna", "Libro", "Caffè", "Nuvola", "Viaggio", "Hotel"};
	bubble_sort(v);
	if (is_sorted(v)){
		return EXIT_SUCCESS;
	}
	else{
		return EXIT_FAILURE;
	}
}
	
	
	
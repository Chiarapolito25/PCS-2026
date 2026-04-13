#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "sort_algorithms.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include <random>
using namespace std;

int main(void){
	random_device rd;
	randfiller rf;
	timecounter tc;
	
	// Intestazione tabella per leggere meglio i risultati
    cout << "Size, t_Bubble, t_Insert, t_Select, t_stdsort \n" << endl;
	
	for (int i=4; i<=8192; i*=2){
		vector<int> vi,v1,v2,v3,v4;
		double t_bubble, t_insert, t_select, t_std;
		vi.resize(i);
		rf.fill(vi,-100,100);
		v1=vi;
		v2=vi;
		v3=vi;
		v4=vi;
		
		//bubble sort
		tc.tic();
		bubble_sort(v1);
		t_bubble=tc.toc();
		
		//insertion sort
		tc.tic();
		insertion_sort(v2);
		t_insert=tc.toc();
		
		//selection sort
		tc.tic();
		selection_sort(v3);
		t_select=tc.toc();
		
		//sort implementato da C++
		tc.tic();
		sort(v4.begin(),v4.end());
		t_std=tc.toc();

		//Stampa i risultati in riga
        std::cout << i << " , " << t_bubble << " , " << t_insert << " , " << t_select << " , " << t_std << " ;\n ";
	}
	
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include "sort_algorithms.hpp"
#include "merge_and_quick.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include <random>
using namespace std;

int main(void){
	random_device rd;
	randfiller rf;
	timecounter tc;
	
	// Intestazione tabella per leggere meglio i risultati
    cout << "Size, t_Bubble, t_Insert, t_Select,t_Merge, t_Quick, t_stdsort \n" << endl;
	
	double t_bubble, t_insert, t_select, t_std, t_merge, t_quick;
	
	for (int i=4; i<=8192; i*=2){
		vector<vector<int>> V(100, vector<int>(i)),V_temp(100, vector<int>(i));
		for (int j=0; j<100;j++){
			rf.fill(V[j],-100,100);
		}
		
		
		//bubble sort
		V_temp=V;
		tc.tic();
		for (int j=0; j<100;j++){
			bubble_sort(V_temp[j]);
		}
		t_bubble=tc.toc()/100;
		
		//insertion sort
		V_temp=V;
		tc.tic();
		for (int j=0; j<100;j++){
			insertion_sort(V_temp[j]);
		}
		t_insert=tc.toc()/100;
		
		//selection sort
		V_temp=V;
		tc.tic();
		for (int j=0; j<100;j++){
			selection_sort(V_temp[j]);
		}
		t_select=tc.toc()/100;
		
		//merge sort
		V_temp=V;
		tc.tic();
		for (int j=0; j<100;j++){
			merge_sort(V_temp[j], 0, i-1);
		}
		t_merge=tc.toc()/100;
		
		//quick sort
		V_temp=V;
		tc.tic();
		for (int j=0; j<100;j++){
			quick_sort(V_temp[j], 0, i-1);
		}
		t_quick=tc.toc()/100;
		
		
		//sort implementato da C++
		V_temp=V;
		tc.tic();
		for(int j=0; j<100; j++){
			sort(V_temp[j].begin(),V_temp[j].end());
		}
		t_std=tc.toc()/100;

		//Stampa i risultati in riga
        cout << i << " , " << t_bubble << " , " << t_insert << " , " << t_select << " , " << t_merge << " , " << t_quick<< " , " << t_std << " ;\n ";
	}
	
	return 0;
}
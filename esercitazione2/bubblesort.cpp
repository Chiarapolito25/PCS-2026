#include <iostream>

using namespace std;
int main()
{
	static const int N=10; //ovvero da 0 a 9
	double arr[N];
	for (int i=0; i<N; i++) {
		arr[i]=rand() ;
		
	}
	
	
	cout<<"dato il vettore: [";
	for (int i=0; i<N; i++) {
		cout << " " <<arr[i] << " ";
		
	}
	cout<<"]\n";
	

	for (int i=0; i<N-1; i++) {
		if (arr[i+1] < arr[i]){
			int j=i;
			while(j>=0){
				if (arr[j+1] < arr[j]){
					double scambio;
					scambio=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=scambio;
				}
				j=j-1;
				
			}
		}
		
	}
	
	
	cout << "il vettore ordinato è : [";
	for (int i=0; i<N; i++) {
		cout << " " <<arr[i] << " ";
		
	}
	cout<<"]\n";
	
	
	return 0;

}
#include <iostream>
#include <cmath>     // Per sqrt 
#include <cstdlib>   // Per rand
#include <algorithm> // Per min e max

using namespace std;
int main()
{
	static const int N=10; //ovvero da 0 a 9
	double arr[N];
	double minimo, massimo, rad_quad[N];
	for (int i=0; i<N; i++) {
		arr[i]=rand();
		if (i==0){
		minimo=arr[i];
		massimo=arr[i];
		}
		else{
			minimo=min(minimo, arr[i]);
			massimo=max(massimo, arr[i]);
		}
		
		rad_quad[i]=sqrt(arr[i]);
	}
	
	
	double sum,sum2, mean, dev_standard;
	for (int i=0; i<N ; i++) {
		sum+=arr[i];
	}
	
	mean=sum/N;
	
	
	for (int i=0; i<N; i++) {
		sum2+=(arr[i]-mean)*(arr[i]-mean);
	}
	dev_standard=sqrt(sum2/N);
		
	
	cout << "dato il vettore: [";
	for (int i=0; i<N ; i++) {
		cout << arr[i]<< " ";
	}
	cout << "]" << "\n";
	
	cout << "il minimo è " << minimo << "\n";
	cout << "il massimo è " << massimo << "\n";
	cout << "la radice quadrata è : [" ;
	for (int i=0; i<N ; i++) {
		cout << rad_quad[i]<<" ";
	}
	cout << "]" << "\n";
	cout << "la media è " << mean << "\n";
	cout << "la deviazione standard è " << dev_standard << "\n";
	
	return 0;
}
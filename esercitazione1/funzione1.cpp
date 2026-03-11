#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, const char *argv[]){
string filename=argv[1];
ifstream ifs(filename);

if ( ifs.is_open() ) { 
	for (int i=0; i <=3; i++) {
			string location;
			double temp1;
			double temp2;
			double temp3;
			double temp4;
			
			if (ifs >> location >> temp1 >> temp2 >> temp3 >> temp4){
				double mean_temp=(temp1+temp2+temp3+temp4)/4.0;
				cout << location << " : " << mean_temp << "\n";
			}
		
	}
}
return 0;
}
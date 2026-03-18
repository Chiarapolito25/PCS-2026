//base 16 : da 0 a 9 e da A=10 a F=15
// 9-->1001, A-->1010, F-->1111
//quando stampo il numero il prefisso "0x" significa che il numero è esadecimale
//0x89 --> ha 2 numeri esadecimali -->0x89=10001001=2^0+2^3+2^7=133 in base 10

#include <iostream>

int main()
{
	double ad[4] = {0.0, 1.1, 2.2, 3.3};
	float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	int ai[3] = {0,1,2};

	int x=1;
	float y=1.1;

	(&y)[1]=0; //scrivo 0 subito dopo y

	std::cout << x << "\n";
	std::cout << &x << "\n";
	std::cout << &y << "\n";
	
	std::cout << &ad <<"\n";
	std::cout << &af <<"\n";
	std::cout << &ai <<"\n";
	return 0;
}

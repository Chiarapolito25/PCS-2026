#include <iostream>
#include "rational.hpp"

int main(void)
{
	rational<int> a(-27,60);
	rational<int> b(-15, 10);

	rational<int> c = a+b;
	std::cout <<"("<< a << ") + (" << b << ") = "<< c << "\n";
	
	rational<int> d = a-b;
	std::cout <<"("<< a << ") - (" <<b<< ") = "<< d << "\n";
	
	rational<int> e= a*b;
	std::cout <<"("<< a << ") * (" << b << ") = "<< e << "\n";
	
	rational<int> f = a/b;
	std::cout << "("<< a << ") / (" << b << ") = "<< f << "\n";
	
	
	return 0;
}
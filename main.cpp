
#include "IntHuge.h"
#include <iostream>

int main() {
	int size = 1, error = 0;
	
	IntHuge A(size, error);
	std::cout << "\n Input A: ";
	std::cin >> A;
	std::cout << " A = ";
	std::cout << A;

	IntHuge B(size, error);
	std::cout << "\n Input B: ";
	std::cin >> B;
	std::cout << " B = ";
	std::cout << B;

	std::cout << "\n A + B = ";
	std::cout << A + B;
	return 0;
}
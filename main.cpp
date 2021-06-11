
#include "IntHuge.h"
#include <iostream>

int main() {
	int size = 3, error = 0;
	
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

	std::cout << "\n\n/------------------------------------/";

	std::cout << "\n  Math Operators:  ";
	std::cout << "\n  A + B = ";
	std::cout << (A + B);


	std::cout << "\n\n/------------------------------------/";

	std::cout << "\n  Comparsion Operators:  ";
	std::cout << "\n  A == B? ";
	std::cout << (A == B);
	std::cout << "\n  A != B? ";
	std::cout << (A != B);
	std::cout << "\n  A < B? ";
	std::cout << (A < B);
	std::cout << "\n  A > B? ";
	std::cout << (A > B);
	std::cout << "\n  A >= B? ";
	std::cout << (A >= B);
	std::cout << "\n  A <= B? ";
	std::cout << (A <= B);

	std::cout << "\n\n/------------------------------------/";
	return 0;
}
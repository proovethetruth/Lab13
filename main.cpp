
#include "IntHuge.h"
#include <iostream>

int main() {
	size_t size = 1;
	int error = 0;
	
	IntHuge A(size, error);
	if (error == 1)
	{
		std::cout << "\n Incorrect size input";
		return -1;
	}
	std::cout << "\n Input A: ";
	std::cin >> A;
	std::cout << " A = ";
	std::cout << A;

	IntHuge B(size, error);
	if (error == 1)
	{
		std::cout << "\n Incorrect size input";
		return -1;
	}
	std::cout << "\n Input B: ";
	std::cin >> B;
	std::cout << " B = ";
	std::cout << B;

	std::cout << "\n\n/------------------------------------/";

	std::cout << "\n  Math Operators:  ";
	//std::cout << "\n  A = B: ";
	//A = B;
	//std::cout << A;
	// std::cout << "\n  A + B = " << A + B;

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
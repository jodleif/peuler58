#include <iostream>
#include <limits>
#include "diagonals.h"
int main()
{
	std::cout.sync_with_stdio(false);
	std::cout << "Project Euler - 58\n";
	peuler58::diagonals d;
	std::cout << "Side length: " << d.side_length_when_cond() << "\n";
	std::cin.get();
	return 0;
}
#include <iostream>
#include <limits>
#include "diagonals.h"
#include "timer/bench_timer.h"
int main()
{
	std::cout.sync_with_stdio(false);
	std::cout << "Project Euler - 58\n";
	bench_timer bt;
	peuler58::diagonals d;
	std::cout << "Side length: " << peuler58::find_sidelength() << "\n";
	return 0;
}
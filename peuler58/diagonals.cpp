#include "diagonals.h"
#include "sieve.h"

void peuler58::diagonals::first_layer()
{
	diag1.push_back(1u);
	diag1.push_back(3u);
	diag2.push_back(5u);
	diag1.push_back(7u);
	diag2.push_back(9u);
	primes = 3;
	diag_count = 5.0;
}

double peuler58::diagonals::ratio(std::size_t primes, double total)
{
	return (primes / total);
}

peuler58::diagonals::diagonals()
{
	first_layer();
}


peuler58::diagonals::~diagonals()
{
}

bool peuler58::diagonals::next_layer(uint_fast32_t layer)
{
	auto base = *diag2.rbegin(); // last element in current layer
	auto diag1_1 = base + (layer * 2);
	auto diag2_1 = base + (layer * 2) * 2;
	auto diag1_2 = base + (layer * 2) * 3;
	auto diag2_2 = base + (layer * 2) * 4;
	for(auto elem : {diag1_1, diag1_2}) {
		if (is_prime(elem)) ++primes;
		diag1.push_back(elem);
	}
	for(auto elem : {diag2_1, diag2_2}) {
		if (is_prime(elem)) ++primes;
		diag2.push_back(elem);
	}
	diag_count += 4.0;
	if (ratio(primes,diag_count) < 0.1) return true; // Condition met
	return false;
}

uint_fast32_t peuler58::diagonals::side_length_when_cond()
{
	uint_fast32_t iteration{ 2 };
	while (!next_layer(iteration++));
	--iteration; // Gets incremented after call.
	return (iteration * 2)+1; // Side = Iteration *2 +1 (middle)
}

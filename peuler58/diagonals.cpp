#include "diagonals.h"
#include "sieve.h"

uint_fast32_t peuler58::find_sidelength()
{

	uint64_t tmp = 9; // get same type
	uint64_t layer = 4;
	uint64_t primes = 3;
	while ((primes /static_cast<double>(layer*2+1)) > 0.1) {
		for (uint_fast32_t i{ 0 };i < 3u;++i) {
			tmp += layer;
			if (is_prime(tmp)) ++primes;
		}
		tmp += layer;
		layer += 2;
	}
	return layer + 1;
}

void peuler58::diagonals::first_layer()
{
	last = 9u;
	primes = 3;
	diag_count = 5.0;
}

double peuler58::diagonals::ratio(std::size_t primes, double total) const
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
	auto base = last; // last element in current layer
	auto tmp = last; // get same type
	for (uint_fast32_t i{ 1 };i <= 4u;++i) {
		tmp = base + (layer * 2)*i;
		if (is_prime(tmp)) ++primes;
	}
	last = tmp; // update object state
	diag_count += 4.0;
	if (ratio(primes, diag_count) < 0.1) return true; // Condition met
	return false;
}

uint_fast32_t peuler58::diagonals::side_length_when_cond()
{
	uint_fast32_t iteration{ 2 };
	while (!next_layer(iteration++));
	--iteration; // Gets incremented after call.
	return (iteration * 2) + 1; // Side = Iteration *2 +1 (middle)
}

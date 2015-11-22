#include "diagonals.h"

uint_fast32_t peuler58::find_sidelength()
{
	uint64_t tmp = 9; // get same type
	uint64_t layer = 2;
	uint64_t primes = 3;
	uint32_t total = 5;
	while ((primes/static_cast<double>(total)) > 0.1) {
		layer += 2;
		for (uint_fast32_t i{ 0 };i < 3u;++i) {
			tmp += layer;
			if (is_prime(tmp)) ++primes;
		}
		tmp += layer;
		total += 4;
	}
	return layer + 1;
}


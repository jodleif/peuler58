#include "diagonals.h"

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


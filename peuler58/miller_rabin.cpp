#include "miller_rabin.h"

uint64_t millerrabin::mul_mod(uint64_t a, uint64_t b, uint64_t mod)
{
	uint64_t c;
	int64_t r;

	if (a >= mod) a %= mod;
	if (b >= mod) b %= mod;
	long double x{ static_cast<double>(a) };
	c = x*b / mod;
	r = static_cast<int64_t>(a*b - c*mod) % static_cast<int64_t>(mod);
	return r < 0 ? r + mod : r;
}

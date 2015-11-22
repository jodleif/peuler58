#pragma once
#include <vector>
#include <cstdint>
#include "miller_rabin.h"
namespace peuler58
{
	template<typename Integer>
	bool is_prime(Integer n)
	{
		//if (n < 2047) return millerrabin::is_prime(n, std::vector<Integer>{2});
		if (n < 1373653) return millerrabin::is_prime(n, std::vector<Integer>{2, 3});
		if (n < 9080191) return millerrabin::is_prime(n, std::vector<Integer>{31, 73});
		if (n < 25326001) return millerrabin::is_prime(n, std::vector<Integer>{2, 3, 5});
		return millerrabin::is_prime(n, std::vector<Integer> {2, 3, 5, 7, 11});
	}

	uint_fast32_t find_sidelength();
}


#pragma once
#include <vector>
#include <cstdint>
#include "miller_rabin.h"
namespace peuler58
{
	template<typename Integer>
	bool is_prime(Integer n)
	{
		if (n < 2047) return millerrabin::is_prime(n, std::vector<Integer>{2});
		if (n < 1373653) return millerrabin::is_prime(n, std::vector<Integer>{2, 3});
		if (n < 9080191) return millerrabin::is_prime(n, std::vector<Integer>{31, 73});
		if (n < 25326001) return millerrabin::is_prime(n, std::vector<Integer>{2, 3, 5});
		return millerrabin::is_prime(n, std::vector<Integer> {2, 3, 5, 7, 11});
	}
	class diagonals
	{
		std::vector<uint64_t> diag1;
		std::vector<uint64_t> diag2;
		std::size_t primes;
		double diag_count;

		void first_layer();
		double ratio(std::size_t primes, double total);
	public:
		diagonals();
		~diagonals();

		bool next_layer(uint_fast32_t layer);
		uint_fast32_t side_length_when_cond();
	};
}


/*
Ref: From mathematics to generic programming by A.Stepanov, D.Rose
*/

#pragma once
#include <vector>
#include <algorithm>

namespace peuler58
{
	namespace sieve
	{

		template<typename I, typename N>
		void mark_sieve(I firstIterator, I lastIterator, N factor)
		{
			*firstIterator = false;
			while (lastIterator - firstIterator > factor) {
				firstIterator = firstIterator + factor;
				*firstIterator = false;
			}
		}

		template<typename I, typename N>
		void sieve(I firstIterator, N limit)
		{
			I last = firstIterator + limit;
			std::fill(firstIterator, last, true);
			N i{ 0 };
			N index_square{ 3 };
			N factor{ 3 };
			while (index_square < limit) {
				if (firstIterator[i]) {
					mark_sieve(firstIterator + index_square, last, factor);
				}
				++i;
				index_square += factor;
				factor += N{ 2 };
				index_square += factor;
			}
		}

		// Works for primes > 2
		template<typename T, typename N>
		bool is_prime(const std::vector<T>& primes, N prime_to_check)
		{
			if (!(prime_to_check & 1)) return false; // Even numbers is nonprimes
			N check{ prime_to_check - 3 };
			check >>= 1;
			if (primes[check] != 0) return true;
			return false;
		}

		template<typename T, typename N>
		std::vector<N> get_primes(const std::vector<T>& primes, N type)
		{
			std::vector<N> result;
			result.reserve(primes.size() / 5); // Magic number -- ~ 10% primes below 1million
			result.push_back({ N{2} });
			N incr{ 3 };
			for (const auto& elem : primes) {
				if (elem != 0) result.push_back(incr);
				incr += N{ 2 };
			}
			result.shrink_to_fit();
			return result;
		}

		template<typename T>
		void print_primes(const std::vector<T>& primes)
		{
			uint_fast32_t increment{ 3 };
			for (const auto& elem : primes) {
				if (elem != 0) std::cout << increment << "\n";
				increment += 2;
			}
		}

		template<typename T>
		bool is_prime(const std::vector<T>& primes, T to_check)
		{
			return std::binary_search(primes.begin(), primes.end(), to_check);
		}
	}
}
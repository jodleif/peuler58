#pragma once
#include <vector>
#include <algorithm>
// http://stackoverflow.com/questions/4236673/sample-code-for-fast-primality-testing-in-c-sharp/4236870#4236870
namespace millerrabin
{
	template<typename Integer>
	bool is_prime(Integer prime_to_check, std::vector<Integer> list_to_check)
	{
		Integer ndec = prime_to_check - 1;
		Integer s{ 0 }; // Factorization
		while((ndec&1)==0) {
			ndec >>= 1;
			++s;
		}
		int i, j;
		for (i = 0;i < list_to_check.size();++i) {
			Integer a = std::min(prime_to_check - 2, list_to_check[i]);
			Integer now = mod_power(a, ndec, prime_to_check);
			if (now == 1 || now == (prime_to_check-1)) continue;
			for (j = 1;j < s;++j) {
				now = mul(now, now, prime_to_check);
				if (now == (prime_to_check-1)) break;
			}
			if (j == s) return false;
		}
		return true;
	}

	template<typename Integer>
	Integer mul(Integer a, Integer b, Integer mod)
	{
		int i;
		Integer now = 0;
		for (i = sizeof(Integer)*8-1;i >= 0;i--) {
			if ((a >> i) & 1) break;
		}
		for (;i >= 0;i--) {
			now <<= 1;
			while (now > mod) now -= mod;
			if ((a >> i) & 1) now += b;
			while (now > mod) now -= mod;
		}
		return now;
	}
	template<typename Integer>
	Integer pow(Integer a, Integer p, Integer mod)
	{
		if (p == 0) return 1;
		if (!(p&1)) return pow(mul(a, a, mod), p / 2, mod);
		return mul(pow(a, p - 1, mod), a, mod);
	}

	template<typename Integer>
	Integer mod_power(Integer base, Integer ex, Integer mod)
	{
		Integer res{ 1 };
		Integer base_t = base%mod;
		while(ex>0) {
			if(ex&1) {
				res = res*base_t;
				res = res%mod;
			}
			ex >>= 1;
			base_t = base_t*base_t;
			base_t = base_t%mod;
		}
		return res%mod;
	}
	/*
	template<typename Integer, typename Int>
	Integer pow(Integer x, Int n)
	{
		Integer p, y;
		y = 1;
		p = x;
		while(1) {
			if (n & 1) y = p*y;
			n >>= 1;
			if (n == 0) return y;
			p = p*p;
		}
	}*/
}

#include <bits/stdc++.h>
using namespace std;

// MEMO
//
// prime_factorization(n): 素因数分解。O(root(n))。
// eratosthenes(n): 素数判定表作成。O(n log log n)。
// prime_list(n): 素数列挙。

// THE BEGINNING OF THE LIBRARY.

template< typename T >
map< T, int > prime_factorization(T n) {
	map< T, int > res;
	for (T i = 2; i * i <= n;i++) {
		while (n % i == 0) {
			res[i]++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

vector< bool > eratosthenes(int n) {
	vector< bool > is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

vector< int > prime_list(int n) {
	vector< int > res;
	auto is_prime = eratosthenes(n);
	for (int i = 0; i <= n; i++) {
		if (is_prime[i]) {
			res.push_back(i);
		}
	}
	return res;
}

// THE ENDING OF THE LIBRARY.
// THE FOLLOWING IS AN EXAMPLE OF USE.

int main() {
	return 0;
}

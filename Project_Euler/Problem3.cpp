#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> sieve(int n) {
	vector<int> nt(n+1, 1);
	nt[0] = nt[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (!nt[i]) continue;
		for (int j = i * i; j <= n; j += i)
			nt[j] = 0;
	}
	return nt;
}

int main() {
	ll n = 600851475143;
	vector<int> v = sieve(1e7);
	for (int i = 1e7; i >= 0; i--) {
		if (v[i] && n % i == 0) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
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
	int n = 2e6;
	vector<int> v = sieve(n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i]) sum += i;
	}
	cout << sum;
	return 0;
}
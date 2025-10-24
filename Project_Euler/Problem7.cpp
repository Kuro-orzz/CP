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
	int target = 10001;
	vector<int> v = sieve(1e7);
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]) cnt++;
		if (cnt == target) {
			cout << i;
			return 0;
		}
	}
	return 0;
}
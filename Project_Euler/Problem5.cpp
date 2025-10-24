#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> factor(int x) {
	vector<int> res(21, 0);
	for (int i = 2; i <= 20; i++) {
		while (x % i == 0) {
			res[i]++;
			x /= i;
		}
	}
	return res;
}

int main() {
	vector<int> cnt(21, 0);
	for (int i = 1; i <= 20; i++) {
		vector<int> v = factor(i);
		for(size_t j = 0; j < v.size(); j++)
			cnt[j] = max(cnt[j], v[j]);
	}
	ll ans = 1;
	for (int i = 1; i <= 20; i++) {
		ans *= powl(i, cnt[i]);
	}
	cout << ans;
	return 0;
}
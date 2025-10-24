#include <bits/stdc++.h>
using namespace std;

int main() {
	int f[10000];
	f[0] = 1, f[1] = 2;
	int sum = 2;
	int lim = 4e6;
	for (int i = 2; i < 100; i++) {
		f[i] = f[i-1] + f[i-2];
		if (f[i] > lim) break;
		if (f[i] % 2 == 0) sum += f[i];
	}
	cout << sum;
	return 0;
}
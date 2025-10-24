#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 20;

ll row(int a[][N]) {
	ll res = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 17; j++){
			ll mul = 1;
			for (int k = 0; k < 4; k++)	
				mul *= a[i][j+k];
			res = max(res, mul);
		}
	}
	return res;
}

ll col(int a[][N]) {
	ll res = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 17; j++){
			ll mul = 1;
			for (int k = 0; k < 4; k++)	
				mul *= a[j+k][i];
			res = max(res, mul);
		}
	}
	return res;
}

ll diagonally(int a[][N]) {
	ll res = 0;
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			ll mul = 1;
			for (int k = 0; k < 4; k++)
				mul *= a[i+k][j+k];
			res = max(res, mul);
		}
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 3; j < 20; j++) {
			ll mul = 1;
			for (int k = 0; k < 4; k++)
				mul *= a[i+k][j-k];
			res = max(res, mul);
		}
	}
	return res;
}

int main() {
	int a[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	ll ans = 0;
	ans = max({ans, row(a), col(a), diagonally(a)});
	cout << ans;
	return 0;
}
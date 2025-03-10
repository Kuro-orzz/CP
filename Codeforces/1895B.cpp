#include <iostream>
#include <cmath>
#include <algorithm>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define ll long long;
using namespace std;

void solve(){
	int a[1000];
	int n; cin >> n;
	for(int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	if(n % 2 == 0){
		int sum = 0;
		pair<int, int> p[100];
		for(int i = 0; i < n; i++)
			p[i] = {a[i], a[i+n]};
		for(int i = 1; i < n; i++)
			sum += abs(p[i-1].first-p[i].first) + abs(p[i-1].second-p[i].second);
		cout << sum << endl;
		for(int i = 0; i < n; i++)
			cout << p[i].first << " " << p[i].second << endl;
	}
	else{
		pair<int, int> p[100];
		for(int i = 0; i < n - 1; i++)
			p[i] = {a[i], a[i+n]};
		p[n-1] = {a[n-1], a[2*n-1]};
		int sum = 0;
		for(int i = 1; i < n; i++)
			sum += abs(p[i-1].first-p[i].first) + abs(p[i-1].second-p[i].second);
		cout << sum << endl;
		for(int i = 0; i < n; i++)
			cout << p[i].first << " " << p[i].second << endl;
	}
}

int main(){
	//filein();
	//fileout();
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
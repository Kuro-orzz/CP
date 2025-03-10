#include <iostream>
#include <map>
#include <cmath>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
using namespace std;

void solve(){
	int a[106];
	int n; cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n <= 2){
			cout << "Yes" << endl;
			return;
	}
	map<int, int> mp;
	for(int i = 0; i < n; i++)
		mp[a[i]]++;
	if(mp.size() == 1)
		cout << "Yes" << endl;
	else if(mp.size() == 2){
		int x = 0;
		for(auto it : mp){
			if(x == 0)
				x = it.second;
			else if(abs(x-it.second) <= 1)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	else
		cout << "No" << endl;
}

int main(){
	//filein();
	//fileout();
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}
#include <iostream>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	string s, t;
	cin.ignore();
	cin >> s;
	cin >> t;
	bool kt = true;
	for(int i = 1; i < n; i++)
		if(s[i] == s[i - 1])
			kt = false;
	if(kt){
		cout << "Yes" << endl;
		return;
	}
	if(t[0] != t[m-1]){
		cout << "No" << endl;
		return;
	}
	for(int i = 1; i < m; i++)
		if(t[i] == t[i - 1]){
			cout << "No" << endl;
			return;
		}
	for(int i = 1; i < n; i++)
		if(s[i] == s[i - 1] && s[i] == t[0]){
			cout << "No" << endl;
			return;
		}
	cout << "Yes" << endl;
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
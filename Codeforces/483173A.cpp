#include <iostream>
#include <algorithm>
#include <set>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
using namespace std;

void solve(){
	int n; cin >> n;
	set<string> s;
	for(int i = 0; i < n; i++){
		string str; cin >> str;
		string x = str;
		reverse(x.begin(), x.end());
		if(s.find(str) != s.end() or s.find(x) != s.end())
			continue;
		else
			s.insert(str);
	}
	cout << s.size();
}

int main(){
	//filein();
	//fileout();
	solve();
	return 0;
}
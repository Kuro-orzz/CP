#include <iostream>
#include <vector>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
using namespace std;

void solve(){
	int n; cin >> n;
	int max_cnt = 1;
	int cnt = 1;
	string x; cin >> x;
	for(int i = 1; i < n; i++){
		string y; cin >> y;
		if(x != y)
			cnt++;
		x = y;
	}
	cout << cnt;
}

int main(){
	//filein(); fileout();
	solve();	
	return 0;
}
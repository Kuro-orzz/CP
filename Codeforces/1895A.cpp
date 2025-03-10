#include <iostream>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define ll long long;
using namespace std;

void solve(){
	int x, y, k; cin >> x >> y >> k;
	if(y < x){
		cout << x << endl;
		return;
	}
	if(x + k < y){
		cout << 2 * y - (x + k) << endl;
		return; 
	}
	else{
		cout << y << endl;
		return;
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
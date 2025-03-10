#include <iostream>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define ll long long
using namespace std;

void solve(){
	int a, b, n; cin >> a >> b >> n;
	if(n == 0){
		cout << a;
		return;
	}
	else if(n == 1){
		cout << b;
		return;
	}
	for(int i = 2, c; i <= n; i++){
		c = a ^ b;
		a = b;
		b = c;
	}
	cout << b;
}

int main(){
	//filein();
	//fileout();
	solve();
	return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <list>	
#include <iomanip>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define ll long long
#define MOD 1000000007
#define N 1000000
using namespace std;

void solve(){
	int a, b; cin >> a >> b;
	int cnt = 0;
	int arr[10000];
	while(true){
		if(b < a){
			cout << "NO" << endl;
			return;
		}
		arr[cnt] = b;
		cnt++;
		if(b == a){
			cout << "YES" << endl;
			break;
		}
		else if(b % 2 == 0)
			b /= 2;
		else if(b % 10 == 1)
			b = (b - 1) / 10;
		else{
			cout << "NO";
			return;
		}
	}
	cout << cnt << endl;
	for(int i = cnt - 1; i >= 0; i--){
		cout << arr[i] << " ";
	}
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
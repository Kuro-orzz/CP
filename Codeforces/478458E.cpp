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
#define N 100000
using namespace std;

ll mu(int x){
	if(x == 0)
		return 1;
	ll res = 1;
	for(int i = 0; i < x; i++)
		res *= 2;
	return res;
}

void solve(){
    int n, m; cin >> n >> m;
    int cnt = 0;
    if(n > m){
        cout << n - m;
        return; 
    }
    int boi = 0;
    while(n < m){
    	n *= 2;
    	boi++;
    	cnt++;
    }
    int x = n - m;
    while(x > 0){
    	if((int)log2(x) <= boi)
        	x -= mu((int)log2(x));
        else
        	x -= mu(boi);
        cnt++;
   }
   cout << cnt;
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
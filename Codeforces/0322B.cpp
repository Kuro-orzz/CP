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

bool check(int a[]){
	int cnt = 0;
	for(int i = 0; i < 3; i++)
		if(a[i] % 3 == 2)
			cnt++;
	return cnt >= 2;
}

void solve(){
	int a[3];
	for(int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a, a+3);
	int res = 0;
	if(check(a) && a[0] >= 2)
		res += (a[0]-2)/3 + (a[1]-2)/3 + (a[2]-2)/3 + 2;
	else
		res += a[0]/3 + a[1]/3 + a[2]/3 + min({a[0]%3, a[1]%3, a[2]%3});
	cout << res;
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
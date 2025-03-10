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

void solve(){
	int n, k; cin >> n >> k;
	cout << n - k << " ";
	for(int i = n - k + 1; i <= n; i++)
		cout << i << " ";
	for(int i = n - k - 1; i > 0; i--)
		cout << i << " ";
	cout << endl;
}

int main(){
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
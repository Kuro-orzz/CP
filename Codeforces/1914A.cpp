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
	int n; cin >> n;
	string s; cin >> s;
	map<char, int> mp;
	for(int i = 0; i < n; i++)
		mp[s[i]]++;
	int res = 0;
	for(auto it : mp)
		if(it.second >= (int)it.first-'A'+1)
			res++;
	cout << res << endl;
}

int main(){
    //filein(); fileout();
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
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
    int n, m; cin >> n >> m;
    pair<int, int> p[1000];
    int cnt = 0;
    int f = 1;
    int s = 1;
    while(n >= f && m >= s){
    	p[cnt] = {f, s};
    	if(cnt % 2 == 0)
    		f++;
    	else
    		s++;
   		cnt++;
    }
    while(f < n){
    	f++;
    	p[cnt] = {f, s - 1};
    	cnt++;
    }
    while(s < m){
    	s++;
    	p[cnt] = {f - 1, s};
    	cnt++;
    }
    cout << cnt++ << endl;
    for(int i = 0; i < cnt-1; i++)
    	cout << p[i].first << " " << p[i].second << endl;
}

int main(){
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}
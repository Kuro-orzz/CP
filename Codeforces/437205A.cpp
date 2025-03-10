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
#include <climits>
#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD 1000000007
#define N 100000
using namespace std;

ll fib[N+1];
ll ctl[1001];

ll cal(int n){
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += ((ctl[i]%MOD) * (ctl[n-i-1]%MOD));
        res %= MOD;
    }
    return res;
}

void catalan(){
    ctl[0] = 1;
    for(int i = 1; i < 1001; i++)
        ctl[i] = cal(i);
}

void fibo(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < N+1; i++)
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
}

void solve(){
    catalan(); fibo();
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << fib[n] << " " << ctl[m] << endl;
    }
}

int main(){
    fast();
    //filein(); fileout();
    // int t; cin >> t;
    // while(t--)
        solve(); 
    return 0;
}
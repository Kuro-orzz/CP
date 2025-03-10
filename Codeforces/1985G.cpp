#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

ll binPow(ll a, ll b){
    if(b == 0)
        return 1;
    ll x = binPow(a, b/2);
    if(b % 2 == 0)
        return (x*x)%MOD;
    else
        return ((x*x)%MOD*a)%MOD;
}

void solve(){
    ll l, r, k; cin >> l >> r >> k;
    ll t1 = binPow(9/k+1, r);
    ll t2 = -binPow(9/k+1, l);
    cout << (t1+t2+MOD) % MOD << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}
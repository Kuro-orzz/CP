#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)

ll multi_mod(ll a, ll b, ll m){
    if (b == 0)
        return 0;
    ll t = multi_mod(a, b/2, m) % m;
    if (b & 1)
        return ((t + t) % m + a % m) % m;
    else
        return (t + t) % m;
}

map<ll, ll> F;

ll f(ll n, ll m){
    if(F[n])
        return F[n];
    ll k = n/2;
    if(n % 2 == 0)
        return F[n] = (multi_mod(f(k, m), f(k, m), m)+multi_mod(f(k-1, m), f(k-1, m), m)) % m;
    else
        return F[n] = (multi_mod(f(k, m), f(k+1, m), m)+multi_mod(f(k-1, m), f(k, m), m)) % m;
}

void solve(){
    ll a, b, m; cin >> a >> b >> m;
    F[0] = F[1] = 1;
    cout << f(__gcd(a, b)-1, m);
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--) 
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

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

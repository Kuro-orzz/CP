#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll multi(ll a, ll b, ll m){
    if(b == 0) return 0;
    ll x = multi(a, b/2, m);
    if(b&1) return ((x+x)%m+a)%m;
    return (x+x)%m;
}

void solve(){
    vector<ll> a(3); cin >> a[0] >> a[1] >> a[2];
    ll m; cin >> m;
    sort(all(a));
    int neg = 0, pos = 0, zero = 0; 
    for(ll i : a){
        if(i < 0) neg++;
        else if(i > 0) pos++;
        else zero++;
    }
    if(neg <= 1) cout << multi(a[1], a[2], m);
    else cout << multi(abs(a[0]), abs(a[1]), m);
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

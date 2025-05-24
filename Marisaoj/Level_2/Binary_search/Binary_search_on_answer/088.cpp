#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
ll n, m, k;
vector<ll> a;

ll check(ll x){
    ll res = 0;
    for(int i = 1; i <= n; i++)
        res += min(x/i, m);
    return res;
}

ll bs(ll l, ll r, ll k){
    ll ans = LLONG_MAX;
    while(l <= r){
        ll mid = l+(r-l)/2;
        if(check(mid) >= k){
            ans = min(ans, mid);
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

void solve(){
    cin >> n >> m >> k;
    cout << bs(0, 1e10, k);
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
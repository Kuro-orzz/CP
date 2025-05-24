#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
int k;
vector<ll> a;

ll calc(ll x){
    return x/3 + x/5 + x/7 - x/3/5 - x/5/7 - x/3/7 + x/3/5/7;
}

ll bs(ll l, ll r, int k){
    ll ans = LLONG_MAX;
    while(l <= r){
        ll mid = l+(r-l)/2;
        if(calc(mid) < k) l = mid+1;
        else{
            ans = min(ans, mid);
            r = mid-1;
        }
    }
    return ans;
}

void solve(){
    cin >> k;
    cout << bs(0, 1e18, k);
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
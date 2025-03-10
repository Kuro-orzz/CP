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
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> a(n);
    vi c(m);
    FOR(i, 0, n) cin >> a[i].fi;
    FOR(i, 0, n) cin >> a[i].se; 
    FOR(i, 0, m) cin >> c[i];
    vector<ll> best(2e6+1, INT_MAX);
    FOR(i, 0, n)
        best[a[i].fi] = min(best[a[i].fi], 1ll*a[i].fi-a[i].se);
    int pos = 0;
    FOR(i, 1, 2e6+1){
        best[i] = min(best[i], best[i-1]);
        if(best[pos] > best[i])
            pos = i;
    }
    vector<ll> dp(2e6+1, 0);
    FOR(i, 1, 2e6+1){
        dp[i] = dp[i-1];
        if(best[i] != INT_MAX && i-best[i] >= 0)
            dp[i] = max(dp[i], dp[i-best[i]]+2);
    }
    ll ans = 0;
    FOR(i, 0, m){
        if(c[i] <= 1e6)
            ans += dp[c[i]];
        else{
            int k = (c[i]-pos)/best[pos];
            ans += 2*k+dp[c[i]-k*best[pos]];
        }
    }
    cout << ans;
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
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
#define maxn 1000006
#define tuple64 tuple<ll, int, int>

void solve(){
    int n, S; cin >> n >> S;
    pii p[n+1];
    for(int i = 1; i <= n; i++)
        cin >> p[i].fi >> p[i].se;
    vector<vector<ll>> dp(n+1, vector<ll>(S+1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= S; j++){
            dp[i][j] = dp[i-1][j];
            if(p[i].fi <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-p[i].fi]+p[i].se);
        }
    cout << dp[n][S];
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
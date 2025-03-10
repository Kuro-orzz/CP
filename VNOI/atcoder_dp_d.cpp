#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, w; cin >> n >> w;
    vector<pii> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].fi >> v[i].se;
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= w; j++){
            if(i == 0)
                dp[i][j] = (j >= v[i].fi ? v[i].se : 0);
            else{
                dp[i][j] = dp[i-1][j];
                if(j >= v[i].fi)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-v[i].fi]+v[i].se);
            }
        }
    cout << dp[n-1][w];
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

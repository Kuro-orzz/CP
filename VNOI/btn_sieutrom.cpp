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
    int n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    if(n == 1){
        cout << v[0];
        return;
    }
    else if(n == 2){
        cout << v[0]+v[1];
        return;
    }
    vector<vector<ll>> dp(n, vector<ll>(3));
    // not take, take and previous, take and not take previous
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = v[0]; 
    dp[1][0] = v[0];
    dp[1][1] = v[0]+v[1];
    dp[1][2] = v[1];
    for(int i = 2; i < n; i++){
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] = max({dp[i-1][2], dp[i-2][1], dp[i-2][2]})+v[i];
        dp[i][2] = max({dp[i-2][0], dp[i-2][1], dp[i-2][2]})+v[i];
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
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

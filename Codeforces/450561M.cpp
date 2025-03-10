// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e7

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define INF ((1ll<<31)-1)
#define mod 20020303
#define bit(mask, i) ((mask>>i)&1)

void solve(){
    int n, k; cin >> n >> k;
    vi dp(n+1);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i <= min(k, n); i++)
        dp[i] = dp[i-1]+1;
    for(int i = k+1; i<=n; i++)
        dp[i] = (dp[i-1]+dp[i-k-1])%mod;
    cout << dp[n];
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // 0: next is positive
    // 1: next is negative
    vector<vector<ll>> dp(n+1, vector<ll>(2, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + a[i]);
    }
    cout << max(dp[n][0], dp[n][1]);
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

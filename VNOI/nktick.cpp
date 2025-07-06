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
    int t[n+1], r[n+1];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 2; i <= n; i++) cin >> r[i];
    r[1] = 0;
    int dp[n+1][3];
    dp[1][0] = 0;
    dp[1][1] = t[1];
    dp[1][2] = INT_MAX;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + t[i];
        dp[i][2] = dp[i-1][0] + r[i];
    }
    cout << min(dp[n][1], dp[n][2]);
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

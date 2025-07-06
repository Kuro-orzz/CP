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
    int n, m; cin >> n >> m;
    int a[n+1], b[m+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i < 2 || j < 2) {
                if (a[i] == b[j]) dp[i][j] = 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            } else {
                if (a[i] == b[j]) dp[i][j] = dp[i-2][j-2] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    cout << dp[n][m];
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
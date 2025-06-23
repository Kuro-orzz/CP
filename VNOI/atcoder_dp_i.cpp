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
    double a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<double>> dp(n+1, vector<double>(n+1));
    // dp[i][j]: first i coin, has j coin ngửa
    dp[1][1] = a[1];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] * (1 - a[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j] * (1-a[i]) + dp[i-1][j-1] * a[i];
        }
    }
    double ans = 0;
    for (int j = 1; j <= n; j++) {
        if (j > n-j) ans += dp[n][j];
    }
    cout << fixed << setprecision(9) << ans;
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

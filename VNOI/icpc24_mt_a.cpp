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

ll dp[101][100001][2];

void solve() {
    int n, W, H; cin >> n >> W >> H;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1e5; j++) {
            dp[i][j][0] = dp[i-1][j][0];
            dp[i][j][1] = dp[i-1][j][1];

            if (j - v[i] < 0) continue;
            // didn't hold any staff
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-v[i]][0] + w[i]);

            // Hold a staff in the past
            dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-v[i]][1] + w[i]);
            // Hold curren staff
            if (w[i] <= H) {
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-v[i]][0]);
            }
        }
    }
    for (int i = 1e5; i >= 0; i--) {
        if (dp[n][i][0] <= W || dp[n][i][1] <= W) {
            cout << i;
            return;
        }
    }
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
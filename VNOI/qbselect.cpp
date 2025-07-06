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

bool isValidState(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] == 1 && a[i] == b[i]) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    int a[5][n+1];
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> state;
    for (int i = 0; i < (1 << 4); i++) {
        vector<int> v(4);
        for (int j = 0; j < 4; j++) {
            if (i >> j & 1) v[j] = 1;
        }
        bool check = true;
        for (int j = 1; j < 4; j++) {
            if (v[j] == v[j-1] && v[j] == 1) check = false;
        }
        if (check) state.push_back(v);
    }
    int m = state.size();
    vector<vector<vector<ll>>> dp(5, vector<vector<ll>>(n+1, vector<ll>(m, -1e18)));
    for (int i = 0; i <= 4; i++) {
        dp[i][0][0] = 0;
    }
    for (int j = 1; j <= n; j++) {
        for (int cur = 0; cur < m; cur++) {
            ll sumMask = 0;
            for (int i = 1; i <= 4; i++) {
                if (state[cur][i-1]) sumMask += a[i][j];
            }
            for (int prev = 0; prev < m; prev++) {
                if (!isValidState(state[cur], state[prev])) continue;
                dp[0][j][cur] = max(dp[0][j][cur], dp[0][j-1][prev] + sumMask);
            }
        }
    }
    ll ans = LLONG_MIN;
    for (int k = 0; k < m; k++) {
        ans = max(ans, dp[0][n][k]);
    }
    if (ans > 0) {
        cout << ans;
        return;
    }
    ans = LLONG_MIN;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            ans = max(ans, 1ll*a[i][j]);
        }
    }
    cout << ans;
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
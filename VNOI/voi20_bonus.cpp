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

const int N = 306;
int n, k, a[N];
ll dp[N][N][N>>1];

ll calc(int l, int r, int k) {
    if (k == 0) return 0;
    if (l > r) return -1e18;
    if (dp[l][r][k] != -1) return dp[l][r][k];
    ll res = max(calc(l+1, r, k), calc(l, r-1, k));
    if (l > r-1) return dp[l][r][k] = res;
    res = max(res, calc(l, r-2, k-1) + abs(a[r]-a[r-1]));
    res = max(res, calc(l+2, r, k-1) + abs(a[l]-a[l+1]));
    res = max(res, calc(l+1, r-1, k-1) + abs(a[l]-a[r]));
    return dp[l][r][k] = res;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int u = 0; u < (N>>1); u++) {
                dp[i][j][u] = -1;
            }
        }
    }
    cout << calc(1, n, k);
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
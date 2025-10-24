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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> f(n, vector<int>(n));
    pii ans = {0, 0};
    int eq = 0;
    for (int i = 0; i < n; i++) {
        int equal = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) equal++;
            if (a[i] > a[j]) {
                f[i][j] = f[i][j-1] + 1;
            } else {
                f[i][j] = f[i][j-1];
            }
            if (2 * f[i][j] - j + i + equal > 2 * f[ans.fi][ans.se] - ans.se + ans.fi + eq) {
                ans = {i, j};
                eq = equal;
            }
        }
    }
    cout << ans.fi+1 << ' ' << ans.se+1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
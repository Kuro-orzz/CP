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

vector<vector<pii>> adj;
vector<int> vis, dp;

void dfs(int u, int cur_val) {
    dp[u] = cur_val;
    vis[u] = 1;
    for (auto it : adj[u]) {
        auto [v, w] = it;
        if (vis[v]) continue;
        dfs(v, cur_val ^ w);
    }
}

void solve() {
    int n; cin >> n;
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vis.resize(n+1);
    dp.resize(n+1);
    dfs(1, 0);

    vector<int> cntOne(27);
    for (int i = 0; i < 27; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j] >> i & 1) cntOne[i]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 27; i++) {
        ans += 1ll * cntOne[i] * (n - cntOne[i]) * (1 << i);
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
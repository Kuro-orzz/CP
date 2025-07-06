/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "ship"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

struct Lca {
    vector<vector<int>> tree, up, mx;
    vector<int> h, a;

    Lca() {}
    Lca(int n, vector<int> &_a): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {
        mx.resize(n+1, vector<int>(20));
        a = _a;
    }

     // up[n][32]: from i up to 2^j
    void dfs(int u, int p) {
        up[u][0] = p;
        mx[u][0] = a[u];
        for(int j = 1; j < 20; j++) {
            up[u][j] = up[up[u][j-1]][j-1];
            mx[u][j] = max(mx[u][j-1], mx[up[u][j-1]][j-1]);
        }
        for(int v : tree[u]) {
            if(v == p) continue;
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }

    void addEdge(int u, int v) {
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    int query(int u, int v) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u]-h[v];
        u = ancestor_k(u, k);
        if(u == v) return u;

        k = __lg(h[u]);
        for(int j = k; j >= 0; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        int node = query(u, v);
        return h[u] + h[v] - 2 * h[node];
    }

    int ancestor_k(int u, int k) {
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1) {
                u = up[u][j];
            }
        }
        return u;
    }

    int max_point(int u, int v) {
        int node = query(u, v);
        int res = max({mx[u][0], mx[v][0], mx[node][0]});
        int k = dist(u, node);
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1) {
                res = max(res, mx[u][j]);
                u = up[u][j];
            }
        }
        k = dist(v, node);
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1) {
                res = max(res, mx[v][j]);
                v = up[v][j];
            }
        }
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    Lca lca(n, a);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        lca.addEdge(u, v);
    }
    lca.dfs(1, 0);
    vector<ll> dp(n+1, -1);
    dp[1] = 0;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        if (dp[u] == -1) continue;
        dp[v] = max(dp[v], dp[u] + lca.max_point(u, v));
    }
    cout << *max_element(all(dp));
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

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

struct Dsu {
    vector<int> par, sz;
    vector<int> h;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (h[a] > h[b]) swap(a, b);
        par[b] = a;
    }

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }
};

struct Lca {
    vector<vector<int>> tree, up;
    vector<int> h;

    Lca() {}
    Lca(int n): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {}

    void dfs(int u, int p) {
        for(int v : tree[u]) {
            if(v == p) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            for(int j = 1; j < 20; j++) {
                up[v][j] = up[up[v][j-1]][j-1];
            }
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
            if(k >> j & 1)
                u = up[u][j];
        }
        return u;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    Lca lca(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        lca.addEdge(u, v);
    }
    lca.dfs(1, 0);
    Dsu dsu(n+1);
    dsu.h = lca.h;
    vector<int> ans(n+1);
    while (q--) {
        int x, y, z; cin >> x >> y >> z;
        while (lca.h[y] > lca.h[x]) {
            y = dsu.find(y);
            if (lca.h[y] <= lca.h[x]) break;
            if (!ans[y]) ans[y] = z;
            dsu.merge(y, lca.up[y][0]);
            y = lca.up[y][0];
        }
        if (!ans[x]) ans[x] = z;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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
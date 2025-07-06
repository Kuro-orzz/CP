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

vector<vector<int>> adj;
map<pii, pii> mp;
vector<int> cnt;
ll ans = 0;

ll dfs(int u, int par = -1) {
    ll c = cnt[u];
    for (int v : adj[u]) {
        if (v == par) continue;
        c += dfs(v, u);
    }
    if (mp.count({u, par})) {
        ans += min(c * mp[{u, par}].fi, 1ll * mp[{u, par}].se);
    } else if (mp.count({par, u})) {
        ans += min(c * mp[{par, u}].fi, 1ll * mp[{par, u}].se);
    }
    return c;
}

void solve() {
    int n; cin >> n;
    Lca lca(n);
    adj.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b, c1, c2; cin >> a >> b >> c1 >> c2;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        mp[{a, b}] = {c1, c2};
        lca.addEdge(a, b);
    }
    lca.dfs(1, 0);
    cnt.resize(n+1);
    for (int i = 1; i < n; i++) {
        int t = lca.query(i, i+1);
        cnt[i]++; cnt[i+1]++;
        cnt[t] -= 2;
    }
    dfs(1);
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
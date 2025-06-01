#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

struct Lca {
    vector<vector<int>> tree, up;
    vector<int> h;

    Lca() {}
    Lca(int n): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {}

    void dfs(int u, int p = -1) {
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

void solve(){
    int n, q; cin >> n >> q;
    Lca lca(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        lca.addEdge(u, v);
    }
    lca.dfs(1);
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca.query(u, v) << ' ';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
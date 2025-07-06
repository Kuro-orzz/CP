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

    Dsu(int n): par(n+1), sz(n+1, 1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }
};

struct Edge {
    int u, v, w;
    Edge() {}
    Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

ll kruskal(int n, vector<Edge> &edges) {
    auto cmp = [&](Edge a, Edge b) {
        return a.w < b.w;
    };
    sort(all(edges), cmp);
    Dsu g(n);
    ll ans = 0;
    for (auto [u, v, w] : edges) {
        if (g.find(u) != g.find(v)) {
            ans += w;
            g.merge(u, v);
        }
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    cout << kruskal(n, e);
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

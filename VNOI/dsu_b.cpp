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
    vector<int> par, sz, mx, mn;

    Dsu(int n): par(n+1), sz(n+1, 1), mx(n+1), mn(n+1) {
        iota(all(par), 0);
        iota(all(mx), 0);
        iota(all(mn), 0);
    }

    int find(int v) {
        if(v == par[v]) return v;
        int r = find(par[v]);
        mx[r] = max(mx[r], v);
        mn[r] = min(mn[r], v);
        return par[v] = r;
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        mx[a] = max(mx[a], mx[b]);
        mn[a] = min(mn[a], mn[b]);
    }

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }

    int minVertex(int u) { return mn[find(u)]; }

    int maxVertex(int u) { return mx[find(u)]; }
};

void solve() {
    int n, m; cin >> n >> m;
    Dsu g(n);
    while (m--) {
        string type; cin >> type;
        if (type == "union") {
            int u, v; cin >> u >> v;
            g.merge(u, v);
        } else {
            int u; cin >> u;
            cout << g.minVertex(u) << " " << g.maxVertex(u) << " " << g.component_size(u) << '\n';
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

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

    ~Dsu() {}
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> u(m), v(m);
    vector<pii> query(q);
    vector<int> l(q, 0), r(q, m-1), ans(q, -1);
    for (int i = 0; i < m; i++) cin >> u[i] >> v[i];
    for (int i = 0; i < q; i++) {
        cin >> query[i].fi >> query[i].se;
        if (query[i].fi == query[i].se) {
            ans[i] = 0;
            l[i] = r[i] + 1;
        }
    }
    while (true) {
        vector<vector<int>> candidate(m);
        bool answered = true;
        for (int i = 0; i < q; i++) {
            if (l[i] <= r[i]) {
                answered = false;
                candidate[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if (answered) break;

        Dsu dsu(n);
        for (int i = 0; i < m; i++) {
            dsu.merge(u[i], v[i]);
            for (int id : candidate[i]) {
                if (dsu.same_component(query[id].fi, query[id].se)) {
                    ans[id] = i+1;
                    r[id] = i - 1;
                } else {
                    l[id] = i + 1;
                }
            }
        }
    }
    for (int x : ans) cout << x << '\n';
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
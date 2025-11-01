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

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), u(q), v(q), l(m+1, 0), r(m+1, q-1), ans(m+1);
    vector<vector<int>> pos(m+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i+1);
    }
    for (int i = 0; i < q; i++) cin >> u[i] >> v[i];

    while (true) {
        vector<vector<int>> candidate(q);
        bool answered = true;
        for (int i = 1; i <= m; i++) {
            if (l[i] <= r[i]) {
                answered = false;
                candidate[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if (answered) break;

        Dsu dsu(n);
        for (int mid = 0; mid < q; mid++) {
            dsu.merge(u[mid], v[mid]);
            for (int id : candidate[mid]) {
                bool isConnected = 1;
                for (int i = 1; i < pos[id].size(); i++) {
                    if (!dsu.same_component(pos[id][i-1], pos[id][i])) {
                        isConnected = 0;
                    }
                }
                if (isConnected && pos[id].size() > 1) {
                    ans[id] = mid + 1;
                    r[id] = mid - 1;
                } else {
                    l[id] = mid + 1;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << (pos[i].size() > 1 && !ans[i] ? -1 : ans[i]) << '\n';
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
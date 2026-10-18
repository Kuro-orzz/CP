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

struct EdmondsKarp {
    int n;
    vector<vector<int>> adj;
    vector<vector<ll>> c, f;
    vector<int> trace;

    EdmondsKarp(int n) : n(n), adj(n + 1), c(n + 1, vector<ll>(n + 1, 0)), f(n + 1, vector<ll>(n + 1, 0)) {}

    void addEdge(int u, int v, ll w) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += w;
    }

    bool bfs(int s, int t) {
        trace.assign(n + 1, 0);
        trace[s] = -1;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (trace[v] || c[u][v] - f[u][v] == 0) continue;
                trace[v] = u;
                q.push(v);
            }
        }
        return trace[t] != 0;
    }

    ll maxFlow(int s, int t) {
        ll res = 0;
        while (bfs(s, t)) {
            ll delta = LLONG_MAX;
            for (int v = t; v != s; v = trace[v]) {
                int u = trace[v];
                delta = min(delta, c[u][v] - f[u][v]);
            }
            for (int v = t; v != s; v = trace[v]) {
                int u = trace[v];
                f[u][v] += delta;
                f[v][u] -= delta;
            }
            res += delta;
        }
        return res;
    }

    bool inA(int u) { return trace[u] != 0; }
};

void solve() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    EdmondsKarp mxFlow(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        mxFlow.addEdge(u, v, w);
    }
    cout << mxFlow.maxFlow(s, t);
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
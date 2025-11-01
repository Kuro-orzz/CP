#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

vector<pii> k;

vector<pii> bfs(int s, int n, vector<vector<pii>> &g) {
    vector<int> vis(100006), d(100001);
    vector<pii> trace(100006, {0, 0});
    queue<int> q;
    trace[1] = {1, 0};
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : g[u]) {
            if (v == n && d[u] + 1 == d[n]) k.push_back({u, w});
            if (vis[v]) continue;
            vis[v] = 1;
            trace[v] = {u, w};
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    k.push_back(trace[n]);
    return trace;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(100006);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pii> trace = bfs(1, n, adj);
    vector<vector<int>> path;
    for (pii x : k) {
        int t = x.fi;
        vector<int> s;
        s.push_back(x.se);
        while (t != 1) {
            s.push_back(trace[t].se);
            t = trace[t].fi;
        }
        reverse(all(s));
        path.push_back(s);
    }
    sort(all(path));
    cout << path[0].size() << '\n';
    for (int x : path[0]) cout << x << ' ';
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
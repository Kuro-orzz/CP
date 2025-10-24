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

double dijkstra(int s, int t, double v, int n, vector<vector<pii>> &g) {
    vector<int> vis(n + 1);
    vector<double> d(n + 1, LLONG_MAX);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({d[s], s});
    d[s] = 0;
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        int delay = max(0, (int)g[u].size() - 2);
        if (u == s || u == t) delay = 0;
        for (auto [k, w] : g[u]) {
            if (d[k] > d[u] + w/v + delay) {
                d[k] = d[u] + w/v + delay;
                pq.push({d[k], k});
            }
        }
    }
    return d[t];
}

void solve() {
    int n, m; cin >> n >> m;
    double v; cin >> v;
    vector<vector<pii>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s, t; cin >> s >> t;
    cout << fixed << setprecision(6) << dijkstra(s, t, v, n, adj);
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

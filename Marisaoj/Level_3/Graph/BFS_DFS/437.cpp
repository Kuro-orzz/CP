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

int n, m, k;
vector<vector<int>> adj;
vector<vector<int>> d;

void bfs(int s) {
    queue<pii> q;
    q.push({s, 0});
    d[s][0] = 0;
    while (!q.empty()) {
        auto [u, dist] = q.front(); q.pop();
        for (int v : adj[u]) {
            if (d[v][(dist+1) % k] != -1) continue;
            d[v][(dist+1) % k] = dist + 1;
            q.push({v, dist+1});
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d.resize(n+1, vector<int>(k, -1));
    bfs(1);
    if (d[n][0] == -1) cout << -1;
    else cout << d[n][0] / k;
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
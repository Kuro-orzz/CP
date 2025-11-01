#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

struct Query {
    int v, d, c;
};

namespace sub1 {
    vector<int> color;

    void bfs(Query query, vector<vector<int>> &adj, int n, int m) {
        auto [v, d, c] = query;
        vector<int> vis(n+1, 0);
        queue<pii> q;
        q.push({v, 0});
        vis[v] = 1;
        color[v] = c;
        while (!q.empty()) {
            auto [u, w] = q.front(); q.pop();
            for (int it : adj[u]) {
                if (vis[it] || w + 1 > d) continue;
                vis[it] = 1;
                color[it] = c;
                q.push({it, w + 1});
            }
        }
    }

    void sol(int n, int m, vector<vector<int>> &adj, int q, vector<Query> query) {
        color.resize(n+1, 0);
        for (int i = 0; i < q; i++) {
            bfs(query[i], adj, n, m);
        }
        for (int i = 1; i <= n; i++) {
            cout << color[i] << '\n';
        }
    }
}

namespace sub2 {
    vector<vector<int>> color;

    void sol(int n, int m, vector<vector<int>> &adj, int q, vector<Query> query) {
        color.resize(n+1, vector<int>(2, 0));
        for (int i = 0; i < q; i++) {
            auto [v, d, c] = query[i];
            color[v][d] = i+1;
        }
        for (int i = 1; i <= n; i++) {
            int last_color = max(color[i][0], color[i][1]);
            for (int v : adj[i]) {
                last_color = max(last_color, color[v][1]);
            }
            if (!last_color) cout << "0\n";
            else cout << query[last_color-1].c << '\n';
        }
    }
}

namespace sub3 {
    vector<int> color, r;

    void bfs(Query query, vector<vector<int>> &adj, int n) {
        auto [s, d, c] = query;
        queue<int> q;
        q.push(s);
        if (!color[s]) color[s] = c;
        r[s] = max(r[s], d);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (!r[u]) continue;
            for (int v : adj[u]) {
                if (!color[v]) {
                    color[v] = c;
                    r[v] = r[u] - 1;
                    q.push(v);
                } else {
                    if (r[u] - 1 > r[v]) {
                        r[v] = r[u] - 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    void sol(int n, int m, vector<vector<int>> &adj, int q, vector<Query> query) {
        color.resize(n+1, 0);
        r.resize(n+1, 0);
        for (int i = q-1; i >= 0; i--) {
            bfs(query[i], adj, n);
        }
        for (int i = 1; i <= n; i++) {
            cout << color[i] << '\n';
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q; cin >> q;
    vector<Query> query(q);
    int mx_d = 0;
    for (int i = 0; i < q; i++) {
        cin >> query[i].v >> query[i].d >> query[i].c;
        mx_d = max(mx_d, query[i].d);
    }
    if (n <= 2e3 && m <= 2e3 && q <= 2e3) {
        sub1::sol(n, m, adj, q, query);
    } else if (mx_d <= 1) {
        sub2::sol(n, m, adj, q, query);
    } else if (n <= 2e5 && m <= 2e5 && q <= 2e5) {
        sub3::sol(n, m, adj, q, query);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
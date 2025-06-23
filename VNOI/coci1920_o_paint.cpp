/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "paint"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

const int N = 1e5 + 5;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;
vector<vector<int>> a, vis;

bool isValid(pii u) { return u.fi > 0 && u.fi <= n && u.se > 0 && u.se <= m; };

struct Dsu_2D {
    int n, m, S;
    vector<vector<pii>> par;
    vector<vector<int>> sz, color;
    vector<vector<set<pii>>> adj, heavy;
    vector<vector<set<pair<int, pii>>>> light;
    vector<vector<int>> isHeavy;

    Dsu_2D() {}
    Dsu_2D(int _n, int _m, const vector<vector<int>> &_color): n(_n), m(_m), color(_color) {
        S = sqrt(n*m);
        par.resize(n+1, vector<pii>(m+1));
        sz.resize(n+1, vector<int>(m+1, 1));
        adj.resize(n+1, vector<set<pii>>(m+1));
        light.resize(n+1, vector<set<pair<int, pii>>>(m+1));
        heavy.resize(n+1, vector<set<pii>>(m+1));
        isHeavy.resize(n+1, vector<int>(m+1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                par[i][j] = {i, j};
            }
        }
    }

    pii find(pii v) {
        if (v == par[v.fi][v.se]) return v;
        return par[v.fi][v.se] = find(par[v.fi][v.se]);
    }

    void merge(pii a, pii b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a.fi][a.se] < sz[b.fi][b.se]) {
            swap(a, b);
        }
        par[b.fi][b.se] = a;
        sz[a.fi][a.se] += sz[b.fi][b.se];

        // small to large
        if (adj[a.fi][a.se].size() < adj[b.fi][b.se].size()) {
            adj[a.fi][a.se].swap(adj[b.fi][b.se]);
        }
        if (light[a.fi][a.se].size() < light[b.fi][b.se].size()) {
            light[a.fi][a.se].swap(light[b.fi][b.se]);
        }
        if (heavy[a.fi][a.se].size() < heavy[b.fi][b.se].size()) {
            heavy[a.fi][a.se].swap(heavy[b.fi][b.se]);
        }
        for (auto it : adj[b.fi][b.se]) {
            it = find(it);
            if (isHeavy[it.fi][it.se]) {
                if (isHeavy[a.fi][a.se]) {
                    heavy[a.fi][a.se].insert(it);
                    heavy[it.fi][it.se].insert(a);
                } else {
                    light[it.fi][it.se].insert({color[a.fi][a.se], a});
                }
            } else if (isHeavy[a.fi][a.se]) {
                light[a.fi][a.se].insert({color[it.fi][it.se], it});
            }
            adj[a.fi][a.se].insert(it);
        }
        for (auto it : heavy[b.fi][b.se]) {
            heavy[a.fi][a.se].insert(it);
        }
        for (auto it : light[b.fi][b.se]) {
            light[a.fi][a.se].insert(it);
        }

        if (!isHeavy[a.fi][a.se] && adj[a.fi][a.se].size() > S) {
            isHeavy[a.fi][a.se] = 1;
            for (auto it : adj[a.fi][a.se]) {
                it = find(it);
                if (it == a) continue;
                light[a.fi][a.se].insert({color[it.fi][it.se], it});
                if (isHeavy[it.fi][it.se]) {
                    heavy[a.fi][a.se].insert(it);
                    heavy[it.fi][it.se].insert(a);
                }
            }
        }
    }

    bool isValid(pii u) { return u.fi > 0 && u.fi <= n && u.se > 0 && u.se <= m; };

    // 4*n*m * log(n*m)
    void build_component() {
        vector<pair<pii, pii>> same_comp;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!isValid({i+dx[k], j+dy[k]})) continue;
                    pii p = find({i, j});
                    pii adj_grid = find({i+dx[k], j+dy[k]});
                    if (color[p.fi][p.se] != color[adj_grid.fi][adj_grid.se]) {
                        adj[p.fi][p.se].insert(adj_grid);
                    } else {
                        same_comp.emplace_back(p, adj_grid);
                    }
                }
            }
        }
        for (auto [it1, it2] : same_comp) {
            merge(it1, it2);
        }
    }

    void paint(pii u, int c) {
        u = find(u);
        if (color[u.fi][u.se] == c) return;
        color[u.fi][u.se] = c;
        vector<pii> same_comp;
        if (!isHeavy[u.fi][u.se]) {
            for (auto it : adj[u.fi][u.se]) {
                it = find(it);
                if (it != u && color[it.fi][it.se] == c) {
                    same_comp.push_back(it);
                }
                if (isHeavy[it.fi][it.se]) {
                    light[it.fi][it.se].insert({color[u.fi][u.se], u});
                }
            }
        } else { // heavy neighbor
            for (auto it : heavy[u.fi][u.se]) {
                it = find(it);
                if (it == u) continue;
                if (color[it.fi][it.se] == c) {
                    same_comp.push_back(it);
                }
            }
            while (1) {
                pair<int, pii> tmp = {color[u.fi][u.se], {-1, -1}};
                auto lb = light[u.fi][u.se].lower_bound(tmp);
                if (lb == light[u.fi][u.se].end()) break;
                auto it = lb->se;
                it = find(it);
                if (lb->fi != color[u.fi][u.se]) break;
                if (color[it.fi][it.se] == c) {
                    same_comp.push_back(it);
                }
                light[u.fi][u.se].erase(lb);
            }
        }
        for (auto it : same_comp) {
            merge(u, it);
        }
    }
} g;

void solve() {
    cin >> n >> m;
    a.resize(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
         }
    }
    g = Dsu_2D(n, m, a);
    g.build_component();
    int q; cin >> q;
    while (q--) {
        int x, y, c; cin >> x >> y >> c;
        g.paint({x, y}, c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pii cur = g.find({i, j});
            cout << g.color[cur.fi][cur.se] << ' ';
        }
        cout << '\n';
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

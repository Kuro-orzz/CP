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

int n, m, s, ans;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<pii> shrines;
vector<vector<vector<int>>> d;
vector<vector<int>> dp;

bool isValid(pii u) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
}

vector<vector<int>> bfs(pii s, vector<vector<char>> &a) {
    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m, -1)); 
    queue<pii> q;
    q.push(s);
    vis[s.fi][s.se] = 1;
    d[s.fi][s.se] = 0;
    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            pii v = {u.fi + dx[k], u.se + dy[k]};
            if (!isValid(v) || a[v.fi][v.se] == '#' || vis[v.fi][v.se]) continue;
            vis[v.fi][v.se] = 1;
            d[v.fi][v.se] = d[u.fi][u.se] + 1;
            q.push(v);
        }
    }
    return d;
}

int calc(int i, int mask) {
    if (dp[i][mask] != -1) return dp[i][mask];
    int nearest = 1e9;
    for (int k = 0; k < s; k++) {
        if (k == i) continue;
        if (mask >> k & 1) {
            int dist = d[k][shrines[i].fi][shrines[i].se];
            nearest = min(nearest, calc(k, mask ^ (1 << i)) + dist);
        }
    }
    return dp[i][mask] = nearest;
}

void solve() {
    cin >> n >> m >> s;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                shrines.push_back({i, j});
            }
        }
    }
    for (auto it : shrines) {
        d.push_back(bfs(it, a));
    }

    if (d[0][0][0] == -1) { cout << -1; return; }
    for (auto it : shrines) {
        if (d[0][it.fi][it.se] == -1) { cout << -1; return; }
    }

    dp.resize(s, vector<int>(1 << s, -1));
    dp[0][0] = 0;
    for (int i = 0; i < s; i++) {
        dp[i][0] = 0;
        dp[i][1 << i] = d[i][0][0];
    }
    int ans = INT_MAX;
    for (int i = 0; i < s; i++) {
        ans = min(ans, calc(i, (1 << s) - 1));
    }
    cout << ans;
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
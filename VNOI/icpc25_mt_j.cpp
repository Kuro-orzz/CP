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

bool isValid(pii u, int n, int m) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
}

void solve() {
    int n, m; cin >> n >> m;
    pii S, D;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') S = {i, j};
            if (a[i][j] == 'D') D = {i, j};
        }
    }
    int d[n][m][4];
    memset(d, 0, sizeof d);
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    queue<tuple<int, int, int>> q;
    q.push({S.fi, S.se, 3});
    while (!q.empty()) {
        auto [nx, ny, nhp] = q.front(); q.pop();
        if (make_pair(nx, ny) == D) {
            cout << d[nx][ny][nhp];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int x = nx + dx[i];
            int y = ny + dy[i];
            if (!isValid({x, y}, n, m)) continue;
            int hp = nhp - (a[x][y] == '+' ? 1 : 0);
            if (hp > 0 && !d[x][y][hp]) {
                d[x][y][hp] = d[nx][ny][nhp] + 1;
                q.push({x, y, hp});
            }
        }
    }
    cout << -1;
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
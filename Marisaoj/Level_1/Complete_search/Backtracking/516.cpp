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

int n, m;
vector<vector<char>> a;
string s;
bool vis[7][7];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(pii u) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
}

bool dfs(pii u, int pos){
    if (pos == s.size()) return true;
    vis[u.fi][u.se] = true;
    for (int i = 0; i < 4; i++) {
        pii v = {u.fi + dx[i], u.se + dy[i]};
        if (isValid(v) && !vis[v.fi][v.se] && a[v.fi][v.se] == s[pos]) {
            if (dfs(v, pos+1)) return true;
        }
    }
    vis[u.fi][u.se] = false;
    return false;
}

void solve() {
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[0] == a[i][j] && dfs({i, j}, 1)) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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
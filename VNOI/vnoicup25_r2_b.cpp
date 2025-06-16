#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

string direction[4] = {"v", ">", "<", "^"};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isValid(pii u, int n, int m) {
    return u.fi >= 0 && u.fi < n && u.se >= 0 && u.se < m;
} 

vector<vector<string>> bfs(pii s, int n, int m) {
    vector<vector<string>> res(n, vector<string>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    vector<int> used(4);
    queue<pii> q;
    q.push(s);
    vis[s.fi][s.se] = 1;
    res[s.fi][s.se] = ".";
    while (!q.empty()) {
        pii v = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            pii k = {v.fi + dx[i], v.se + dy[i]};
            if (!isValid(k, n, m) || vis[k.fi][k.se]) continue;
            vis[k.fi][k.se] = 1;
            used[i] = 1;
            res[k.fi][k.se] = direction[i];
            q.push(k);
        }
    }

    int diagonal_x[4] = {-1, -1, 1, 1};
    int diagonal_y[4] = {-1, 1, 1, -1};
    for (int i = 0; i < 4; i++) {
        pii k = {s.fi + 2*diagonal_x[i], s.se + 2*diagonal_y[i]};
        if (!isValid(k, n, m)) continue;
        if (i == 0) {
            res[1][1] = "<";
            res[1][0] = "^";
        } else if (i == 1) {
            res[1][m-2] = ">";
            res[1][m-1] = "^";
        } else if (i == 2) {
            res[n-2][m-2] = ">";
            res[n-2][m-1] = "v";
            res[n-1][m-1] = "<";
            res[n-1][m-2] = "<";
        } else if (i == 3) {
            res[n-2][1] = "<";
            res[n-2][0] = "v";
            res[n-1][0] = ">";
            res[n-1][1] = ">";
        }
    }

    return res;
}

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<string>> ans = bfs(make_pair(x, y), n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

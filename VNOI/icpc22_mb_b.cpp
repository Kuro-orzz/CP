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

int m, n, s0;
int a[10], b[10];

int bfs(int cur) {
    vector<int> vis(m);
    queue<pii> q;
    q.push({cur, 0});
    vis[cur] = 1;
    while (!q.empty()) {
        pii v = q.front(); q.pop();
        if (!v.fi) return v.se;
        for (int i = 0; i < n; i++) {
            int next = (1ll * v.fi * a[i] + b[i]) % m;
            if (!vis[next]) {
                q.push({next, v.se+1});
                vis[next] = 1;
            }
        }
    }
    return -1;
}

void solve() {
    cin >> m >> n >> s0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cout << bfs(s0);
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
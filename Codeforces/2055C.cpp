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

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    pii cur = {0, 0};
    a[0][0] = 1e9;
    for (char c : s) {
        if (c == 'D') cur.fi++;
        else cur.se++;
        a[cur.fi][cur.se] = 1e9;
    }
    vector<ll> row(n), col(m), missing_row(n), missing_col(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1e9) {
                missing_row[i]++;
                missing_col[j]++;
            } else {
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
    }
    cur = {0, 0};
    if (missing_row[cur.fi] == 1) {
        a[cur.fi][cur.se] = -row[cur.fi];
    } else if (missing_col[cur.se] == 1) {
        a[cur.fi][cur.se] = -col[cur.se];
    }
    row[cur.fi] += a[cur.fi][cur.se];
    col[cur.se] += a[cur.fi][cur.se];
    missing_row[cur.fi]--;
    missing_col[cur.se]--;
    for (char c : s) {
        if (c == 'D') cur.fi++;
        else cur.se++;
        if (missing_row[cur.fi] == 1) {
            a[cur.fi][cur.se] = -row[cur.fi];
        } else if (missing_col[cur.se] == 1) {
            a[cur.fi][cur.se] = -col[cur.se];
        }
        row[cur.fi] += a[cur.fi][cur.se];
        col[cur.se] += a[cur.fi][cur.se];
        missing_row[cur.fi]--;
        missing_col[cur.se]--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
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
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
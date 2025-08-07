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

int n, m, a[21][21], cur[21][21], ans[21][21];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool solved = false;

bool isValid(pii u) { return u.fi > 0 && u.fi <= n && u.se > 0 && u.se <= m; }

void addBomb(pii u) {
    ans[u.fi][u.se] = 1;
    for (int i = 0; i < 8; i++) {
        pii v = {u.fi + dx[i], u.se + dy[i]};
        if (isValid(v)) a[v.fi][v.se]--;
    }
}

void removeBomb(pii u) {
    ans[u.fi][u.se] = 0;
    for (int i = 0; i < 8; i++) {
        pii v = {u.fi + dx[i], u.se + dy[i]};
        if (isValid(v)) a[v.fi][v.se]++;
    }
}

bool boundCheck(int curR, int curC) {
    for (int i = 1; i <= curR-2; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) return false;
        }
    }
    if (curR - 1 < 1) return true;
    for (int j = 1; j < curC; j++) {
        if (a[curR-1][j]) return false;
    }
    return true;
}

void backtrack(int curR, int curC) {
    if (curR > n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) return;
            }
        }
        solved = true;
        return;
    }
    if (!boundCheck(curR, curC)) return;

    int nxtR, nxtC;
    if (curC == m) nxtR = curR+1, nxtC = 1;
    else nxtR = curR, nxtC = curC+1;

    backtrack(nxtR, nxtC);
    if (solved) return;

    addBomb({nxtR, nxtC});
    backtrack(nxtR, nxtC);
    if (solved) return;
    removeBomb({nxtR, nxtC});
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    backtrack(1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
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
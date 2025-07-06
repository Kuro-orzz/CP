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
    int a[n][m];
    int team_solved[n];
    int problem_solved[m];
    memset(team_solved, 0, sizeof team_solved);
    memset(problem_solved, 0, sizeof problem_solved);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]) team_solved[i]++, problem_solved[j]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (team_solved[i] == 0 || team_solved[i] == m) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (problem_solved[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
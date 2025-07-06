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
    int n; cin >> n;
    vector<vector<int>> ans(2, vector<int>(n));
    int mn = 2, mx = 2*n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            ans[0][i] = mx;
            mx -= 2;
            ans[1][i] = mn - 1;
        } else {
            ans[0][i] = mn;
            mn += 2;
            ans[1][n-i] =  mx + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
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
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

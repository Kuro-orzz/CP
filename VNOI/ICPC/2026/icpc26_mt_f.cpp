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
    int n, m, q; cin >> n >> m >> q;
    // left up, right bottom
    pii a = {1e9, -1e9}, b = {-1e9, 1e9};
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.fi = min(a.fi, x);
        a.se = max(a.se, y);
        b.fi = max(b.fi, x);
        b.se = min(b.se, y);
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        a.fi = min(a.fi, x1);
        a.se = max(a.se, y2);
        b.fi = max(b.fi, x2);
        b.se = min(b.se, y1);
    }
    for (int i = 0; i < q; i++) {
        int x, y, r; cin >> x >> y >> r;
        a.fi = min(a.fi, x-r);
        a.se = max(a.se, y+r);
        b.fi = max(b.fi, x+r);
        b.se = min(b.se, y-r);
    }
    ll side = max(b.fi - a.fi, a.se - b.se);
    cout << side * side << '\n';
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

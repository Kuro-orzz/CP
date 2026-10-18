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

/*
Tách riêng trục x, y ra, tính tọa độ trên từng trục sau t time
*/
void solve() {
    ll n, m, x, y, vx, vy; cin >> n >> m >> x >> y >> vx >> vy;
    int q; cin >> q;
    while (q--) {
        ll time; cin >> time;
        ll move_x = time * vx % (2 * (n-1));
        ll move_y = time * vy % (2 * (m-1));
        pair<ll, ll> ans = {x + move_x, y + move_y};
        for (int i = 0; i < 2; i++) {
            if (ans.fi < 1) ans.fi = 2 - ans.fi;
            else if (ans.fi > n) ans.fi = 2 * n - ans.fi;
            if (ans.se < 1) ans.se = 2 - ans.se;
            else if (ans.se > m) ans.se = 2 * m - ans.se;
        }
        cout << ans.fi << ' ' << ans.se << '\n';
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

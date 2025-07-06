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
    int n, a, b; cin >> n >> a >> b;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].fi >> v[i].se;
    }
    sort(all(v));
    int l = 0;
    int ans = INT_MAX;
    // k = 1, k = 2
    int cntTung = 0, cntTruc = 0;
    for (int r = 0; r < n; r++) {
        if (v[r].se == 1) cntTung++;
        else cntTruc++;
        while (cntTung >= a && cntTruc >= b) {
            ans = min(ans, v[r].fi - v[l].fi);
            if (v[l].se == 1) cntTung--;
            else cntTruc--;
            l++;
        }
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
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
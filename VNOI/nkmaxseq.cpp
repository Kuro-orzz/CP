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
    int n, p; cin >> n >> p;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<ll, int>> pref(n);
    pref[0] = {a[0], 0};
    for (int i = 1; i < n; i++) {
        pref[i] = {pref[i-1].fi + a[i], i};
    }
    sort(all(pref));
    vector<int> suff(n);
    suff[n-1] = pref[n-1].se;
    for (int i = n-2; i >= 0; i--) {
        suff[i] = max(suff[i+1], pref[i].se);
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(pref), make_pair(pref[i].fi + p, 0))-pref.begin();
        if (it == n) continue;
        ans = max(ans, suff[it] - pref[i].se);
    }
    cout << ans;
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

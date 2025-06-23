/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "sdb"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(all(a));
    int cnt = 1;
    vector<pii> ans;
    for (int i = 1; i < n; i++) {
        if (a[i].fi == a[i-1].fi) cnt++;
        else {
            if (cnt == 1) ans.push_back(a[i-1]);
            cnt = 1;
        }
    }
    if (cnt == 1) ans.push_back(a[n-1]);
    sort(all(ans), [&](pii a, pii b) { return a.se < b.se; });
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x << '\n';
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

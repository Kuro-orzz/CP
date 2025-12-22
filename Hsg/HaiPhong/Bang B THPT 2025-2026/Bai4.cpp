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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<pair<char, int>> mn, mx;
    for (int i = 0; i < n; i++) {
        mn.emplace_back(s[i], i);
        mx.emplace_back(s[i], i);
    }
    sort(all(mn));
    sort(all(mx), [&](pair<char, int> &a, pair<char, int> &b) {
        if (a.fi != b.fi) return a.fi > b.fi;
        return a.se < b.se;
    });
    vector<int> used(n, 0);
    int p1 = 0, p2 = 0;
    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            while (p1 < n && used[mn[p1].se]) p1++;
            used[mn[p1].se] = 1;
        } else if (type == 1) {
            while (p2 < n && used[mx[p2].se]) p2++;
            used[mx[p2].se] = 1;
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (!used[i]) ans += s[i];
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
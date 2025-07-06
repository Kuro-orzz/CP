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
    int mn_val = 1;
    set<int> s;
    vector<int> c(n+1);
    iota(all(c), 0);
    s.insert(0);
    int prev = 1;
    while (mn_val <= n) {
        while (s.count(c[prev]) && c[prev] + prev <= n) {
            c[prev] += prev;
        }
        if (!s.count(c[prev])) {
            s.insert(c[prev]);
            cout << c[prev] << ' ';
            prev = c[prev];
            continue;
        }
        while (s.count(mn_val) && mn_val <= n) mn_val++;
        if (mn_val <= n) {
            s.insert(mn_val);
            cout << mn_val++ << ' ';
            prev = mn_val-1;
        }
    }
    cout << '\n';
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

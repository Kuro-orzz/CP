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

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

void solve() {
    int u, v; cin >> u >> v;
    ll prod = 1ll * u * v;
    int ans = 0;
    for (int i = u; i <= v; i+=u) {
        if (prod % i) continue;
        ll x = i, y = prod / i;
        if (__gcd(x, y) == u && lcm(x, y) == v) {
            ans++;
        }
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
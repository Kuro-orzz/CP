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

int f[10000006];

void preprocess() {
    f[0] = f[1] = 1;
    for (int i = 2; i <= 1e7; i++) {
        f[i] = 1ll * f[i-1] * i % MOD;
    }
}

using i128 = __int128;

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while (b) {
        if (b & 1) res = (i128)res * a % M;
        a = (i128)a * a % M;
        b /= 2;
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    cout << binPow(f[m], n, MOD) * binPow(f[n], m, MOD) % MOD << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    preprocess();
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

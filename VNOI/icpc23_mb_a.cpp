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

ll f[90];

void fib(int n) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < n; i++) {
        f[i] = f[i-1] + f[i-2];
    }
}

int ans = 0;

void backtrack(vector<ll> &v, int pos, ll cur) {
    if (cur == 1) {
        ans++;
        return;
    }
    if (pos == v.size()) return;
    for (int i = pos; i < v.size(); i++) {
        if (cur % v[i] == 0) backtrack(v, i, cur / v[i]);
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> v;
    for (int i = 3; i < 90; i++) {
        if (f[i] > n) break;
        if (n % f[i] == 0) v.push_back(f[i]);
    }
    ans = 0;
    backtrack(v, 0, n);
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    fib(90);
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
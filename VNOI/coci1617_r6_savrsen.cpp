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

vector<ll> sieve(int n) {
    vector<ll> v(n+1, 1);
    v[1] = 0;
    for (int i = 2; i*i <= n; i++) {
        for (int j = i*i; j <= n; j += i) {
            v[j] += i;
            if (j != i*i) v[j] += j/i;
        }
    }
    return v;
}

void solve() {
    int l, r; cin >> l >> r;
    vector<ll> sumDiv = sieve(r);
    ll ans = 0;
    for(int i = l; i <= r; i++) {
        ans += abs(i-sumDiv[i]);
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
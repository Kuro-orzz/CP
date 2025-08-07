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
    int n, q, S, T; cin >> n >> q >> S >> T;
    vector<int> a(n+1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    vector<ll> diffArray(n+1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i-1] < a[i]) diffArray[i] = 1ll * S * (a[i-1] - a[i]); // decrease
        else diffArray[i] = 1ll * T * (a[i-1] - a[i]); // increase
        ans += diffArray[i];
    }
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        ans -= diffArray[l];

        ll u = 0, v = x;
        if (diffArray[l] > 0) u += diffArray[l] / T;
        else u += diffArray[l] / S;
        
        if (u < v) diffArray[l] = S * (u - v);
        else diffArray[l] = T * (u - v);

        ans += diffArray[l];

        if (r != n) {
            ans -= diffArray[r+1];
           
            ll u = x, v = 0;
            if (diffArray[r+1] > 0) v -= diffArray[r+1] / T;
            else v -= diffArray[r+1] / S;
    
            if (u < v) diffArray[r+1] = S * (u - v);
            else diffArray[r+1] = T * (u - v);
           
            ans += diffArray[r+1];
        }

        cout << ans << '\n';
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
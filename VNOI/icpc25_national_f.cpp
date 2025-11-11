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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pref(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }
    vector<ll> kadane(n), suff(n+1);
    ll sum = 0;
    for (int i = n-1; i >= 0; i--) {
        sum += a[i];
        sum = max(sum, 0ll);
        kadane[i] = sum;
        suff[i] = max(kadane[i], suff[i+1]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, pref[i] + suff[i]);
    }
    cout << ans << '\n';
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

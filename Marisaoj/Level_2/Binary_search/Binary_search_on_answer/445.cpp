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

// Aj >= mid + Ai
bool check(vector<int> &a, ll mid, ll k) {
    int n = a.size();
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(all(a), a[i] + mid + 1) - a.begin();
        cnt += it - i - 1;
    }
    return cnt >= k;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    ll l = 0, r = 1e10;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(a, mid, k)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
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
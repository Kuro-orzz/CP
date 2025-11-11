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

const int mod = 998244353;

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 1;
    sort(a, a+n);
    vector<int> v;
    for (int i = 1; i < n; i++) {
        if (a[i-1] + 1 == a[i]) cnt++;
        else {
            if (cnt > 1) v.push_back(cnt);
            cnt = 1;
        }
    }
    if (cnt > 1) v.push_back(cnt);
    ll ans = 1;
    for (int x : v) {
        if (x % 2 == 0) continue;
        ans = ans * (x + 1) / 2 % mod;
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

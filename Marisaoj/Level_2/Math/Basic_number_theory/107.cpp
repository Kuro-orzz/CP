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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j*j <= a[i]; j++) {
            int cnt = 0;
            while (a[i] % j == 0) {
                cnt++;
                a[i] /= j;
            }
            mp[j] = max(mp[j], cnt);
        }
        if (a[i] > 1) mp[a[i]] = max(mp[a[i]], 1);
    }
    ll ans = 1;
    for (auto it : mp) {
        for (int i = 0; i < it.se; i++) ans = ans * it.fi % MOD;
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
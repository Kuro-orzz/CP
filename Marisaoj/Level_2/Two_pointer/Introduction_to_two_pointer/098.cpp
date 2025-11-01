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
    int n, m; cin >> n >> m;
    int a[n], b[m+1];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<int> cnt(m+1);
    int l = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;
        while (cnt[a[r]] > b[a[r]]) {
            cnt[a[l++]]--;
        }
        ans = max(ans, r-l+1);
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
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
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int p1 = 0, p2 = 0;
    vector<int> mx(n), suff(n);
    for (int i = 0; i < n; i++) {
        while (p1 < n && a[p1] - a[i] <= k) p1++;
        mx[i] = p1 - i;
    }
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) suff[i] = mx[i];
        else suff[i] = max(suff[i+1], mx[i]);
    }
    int ans = 0;
    for (int i = 1 ; i < n; i++) {
        if (i + mx[i]-1 < n) {
           ans = max(ans, mx[i] + suff[i+mx[i]-1]);
        } else {
            ans = max(ans, mx[i]);
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
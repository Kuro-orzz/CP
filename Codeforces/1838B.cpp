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
    int a[n+1], index[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        index[a[i]] = i;
    }
    int mn = min(index[1], index[2]);
    int mx = max(index[1], index[2]);
    if (index[n] < mn) {
        cout << index[n] << " " << mn << '\n';
    } else if (index[n] > mx) {
        cout << index[n] << " " << mx << '\n';
    } else {
        cout << "1 1\n";
    }
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

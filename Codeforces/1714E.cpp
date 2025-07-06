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
    sort(a, a+n, greater<int>());
    if (a[0] == a[n-1]) {
        cout << "Yes\n";
        return;
    }
    if (a[0] % 2) a[0] += a[0] % 10;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (a[i] % 10 != a[0] % 10) {
                a[i] += a[i] % 10;
            } else break;
        }
        if (a[i] % 10 == 0 || a[i] == a[0]) continue;
        a[i] += (a[0] - a[i]) / 20 * 20;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[0]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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

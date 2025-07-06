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
    vector<int> a(1e6+1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= 1e6; i++) {
        for (int j = 2*i; j <= 1e6; j += i)
            a[i] += a[j];
    }
    for (int i = 1e6; i >= 1; i--) {
        if (a[i] >= 2) {
            cout << i;
            return;
        }
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

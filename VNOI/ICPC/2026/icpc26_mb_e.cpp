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

/*

*/
void solve() {
    int n, k; cin >> n >> k;
    int t = 1, x = 2;
    while (t * t < k) {
        t += x;
        x *= 2;
    }
    int mnDist = (1 << n) / x;
    int idx = k - (x/2 - 1) * (x/2 - 1);
    int pairs = (idx - 1) / (t + x/2);
    idx -= pairs * (t + x/2);
    int row = 2 * pairs + 1;
    while (idx) {
        if (row % 2) {
            if (idx <= t) {
                cout << row * mnDist << ' ' << idx * mnDist << '\n';
                break;
            } else {
                idx -= t;
            }
        } else {
            if (idx <= x / 2) {
                cout << row * mnDist << ' ' << (2 * idx - 1) * mnDist << '\n';
                break;
            } else {
                idx -= x/2;
            }
        }
        row++;
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
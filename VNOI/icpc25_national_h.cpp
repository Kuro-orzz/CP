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
    int zero = n - k;
    int one = k;
    int minL = (zero + one) / (one + 1);
    int blk0, blk1;
    if (!zero) blk0 = 0;
    else blk0 = (zero + minL - 1) / minL;
    if (!one) blk1 = 0;
    else blk1 = max(1, blk0 - 1);
    int maxS;
    if (!blk1) maxS = 0;
    else maxS = one / blk1;

    while (zero || one) {
        for (int i = 0; i < min(minL, zero); i++) cout << '0';
        zero -= min(minL, zero);
        for (int i = 0; i < (one < 2*maxS ? one : maxS); i++) cout << '1';
        one -= (one < 2*maxS ? one : maxS);
    }
    cout << '\n';
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

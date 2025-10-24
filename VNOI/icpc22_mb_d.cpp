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

int y, f[10];

void solve() {
    cin >> y;
    f[0] = 1;
    for (int i = 1; i < 10; i++) {
        f[i] = f[i-1] * i;
    }
    string res = "";
    int val = 9;
    while (y) {
        while (y >= f[val]) {
            res += (char)(val + '0');
            y -= f[val];
        }
        val--;
    }
    reverse(all(res));
    for (int i = 1; i < res.size(); i++) {
        if (res[i] == '1') res[i] = '0';
    }
    if (res == '1') res = "0";
    cout << res << '\n';
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
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

void ask(int x) {
    cout << x << '\n';
    cout.flush();
}

void ans(int x) {
    cout << "! " << x << '\n';
    cout.flush();
}

void solve() {
    int l = 1, r = 1e6;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ask(mid);
        string s; cin >> s;
        if (s == "<") r = mid - 1;
        else if (s == ">=") {
            res = mid;
            l = mid + 1;
        }
    }
    ans(res);
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

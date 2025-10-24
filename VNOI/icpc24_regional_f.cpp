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
    string s; cin >> s;
    if (s[0] >= '0' && s[0] <= '9') {
        int val = stoi(s);
        if (val >= 1e8) cout << n-2 << ' ' << n-1 << '\n';
        else cout << n+1 << ' ' << n+2 << '\n';
    } else if (s == "fizz") {
        if (n <= 2) cout << "1 3\n";
        else cout << 1 << ' ' << n-1 << '\n';
    } else if (s == "buzz") {
        if (n <= 2) cout << "-1 -1\n";
        else cout << n-1 << ' ' << n << '\n';
    } else if (s == "fizzbuzz") {
        if (n == 1) cout << "-1 -1\n";
        else cout << 1 << " " << n << '\n';
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
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

const int N = 1e5 + 6;

vector<int> calc_odd(string &s) {
    int n = s.size();
    vector<int> d(n);
    int l = 1, r = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) d[i] = 0;
        else d[i] = min(r-i, d[l+r-i]);
        while (i-d[i]-1 > 0 && i+d[i]+1 < n && s[i-d[i]-1] == s[i+d[i]+1]) {
            d[i]++;
        }
        if (i + d[i] > r) {
            l = i - d[i];
            r = i + d[i];
        }
    }
    return d;
}

vector<int> calc_even(string &s) {
    int n = s.size();
    vector<int> d(n);
    int l = 1, r = 0;
    for (int i = 1; i < n-1; i++) {
        int j = i+1;
        if (j > r) d[i] = 0;
        else d[i] = min(r-j+1, d[l+r-j]);
        while (i-d[i] >= 0 && j+d[i] < n && s[i-d[i]] == s[j+d[i]]) {
            d[i]++;
        }
        if (i + d[i] > r) {
            l = j - d[i];
            r = i + d[i];
        }
    }
    return d;
}

void solve() {
    string s; cin >> s;
    s = '$' + s;
    vector<int> odd = calc_odd(s);
    vector<int> even = calc_even(s);
    ll ans = (int)s.size() - 1;
    for (int x : odd) ans += x;
    for (int x : even) ans += x;
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
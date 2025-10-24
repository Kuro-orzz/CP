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
    vector<pair<int, string>> v = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"}
    };
    string s; cin >> s;
    bool isDigit = true;
    for (char c : s) {
        if (c < '0' || c > '9') isDigit = false;
    }
    if (isDigit) cout << v[stoi(s)].se;
    else {
        pii ans = {-1, 99};
        for (int i = 1; i <= 20; i++) {
            int diff = 0;
            if (v[i].se.size() != s.size()) continue;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != v[i].se[j]) diff++;
            }
            if (diff < ans.se) {
                ans = {i, diff};
            }
        }
        cout << ans.fi;
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

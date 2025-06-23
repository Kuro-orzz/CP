/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "thugon"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

void solve() {
    string s;
    while (getline(cin, s)) {
        string ans = "";
        int cnt = 1;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == s[i-1]) cnt++;
            else {
                if (cnt == 1) ans += s[i-1];
                else ans += to_string(cnt) + s[i-1];
                cnt = 1;
            }
        }
        if (cnt == 1) ans += s.back();
        else ans += to_string(cnt) + s.back();
        cout << ans << '\n';
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

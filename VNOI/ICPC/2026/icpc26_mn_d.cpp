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
    string s; cin >> s;
    int n = s.size();
    bool check = true;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) continue;
        check = false;
        break;
    }
    if (check) {
        cout << -1 << '\n';
        return;
    }

    vector<int> cnt(26, 0);
    for (char &c : s) cnt[c-'A']++;
    int op = 0, remain = 0;
    for (int i = 0; i < 26; i++) {
        op += cnt[i] / 2;
        cnt[i] -= cnt[i] / 2 * 2;
        remain += cnt[i];
    }
    if (remain == 1) {
        op--;
        remain += 2;
    } else if (remain == 0) {
        op -= 2;
        remain += 4;
    }
    cout << op + 1 << '\n';
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

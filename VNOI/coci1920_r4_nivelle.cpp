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
    int diff = 1e9;
    pii ans = {1, 1};
    for (int i = 1; i <= 26; i++) {
        int l = 0, cur_diff = 0;
        vector<int> cnt(26);
        for (int r = 0; r < n; r++) {
            int k = s[r] - 'a';
            if (cnt[k]) cnt[k]++;
            else cnt[k]++, cur_diff++;
            while (cur_diff > i) {
                int c = s[l] - 'a';
                cnt[c]--;
                if (!cnt[c]) cur_diff--;
                l++;
            }
            if ((double)diff / (ans.se - ans.fi + 1) > (double)cur_diff / (r - l + 1)) {
                diff = cur_diff;
                ans = {l+1, r+1};
            }
        }
    }
    cout << ans.fi << " " << ans.se;
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
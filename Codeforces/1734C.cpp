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
    vector<int> t(n+1);
    for (int i = 0; i < (int)s.size(); i++) {
        t[i+1] = s[i] - '0';
    }
    vector<vector<int>> mn_cost(n+1);
    for (int i = 1; i <= n; i++) mn_cost[i].push_back(i);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i]) continue;
        ans += *min_element(all(mn_cost[i]));
        for (int x : mn_cost[i]) {
            if (i + x <= n) mn_cost[i + x].push_back(x);
        }
    }
    cout << ans << '\n';
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

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
    vector<int> t(n), v(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> v[i];
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++) {
        pq.push({v[i] + t[i], i});
    }
    int cur_time = 0;
    while (!pq.empty()) {
        auto [sum, idx] = pq.top(); pq.pop();
        int val = sum - t[idx];
        int time = t[idx];
        if (time <= cur_time) continue;
        else {
            v[idx] += time - cur_time;
            cur_time = time;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1ll * v[i] * v[i];
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

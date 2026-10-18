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
    vector<int> a, cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (!a.empty() && a.back() == x) {
            cnt.back()++;
        } else {
            a.push_back(x);
            cnt.push_back(1);
        }
    }
    n = a.size();
    vector<int> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + cnt[i-1];
    }

    auto calc = [&](int l, int r) {
        ll len = pref[r+1] - pref[l];
        return len * (len - 1) / 2;
    };

    int l = 0, r = 1, flag;
    ll ans = 0;
    while (r < n) {
        if (l == r - 1) {
            if (a[l] > a[r]) flag = 1;
            else flag = 0;
        } else {
            if ((flag == 0 && a[r-1] > a[r]) || (flag == 1 && a[r-1] < a[r])) {
                flag ^= 1;
            } else {
                ans += calc(l, r-1);
                if (l) ans -= calc(l, l);
                l = r - 1;
                continue;
            }
        }
        r++;
    }
    ans += calc(l, r-1);
    if (l) ans -= calc(l, l);
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

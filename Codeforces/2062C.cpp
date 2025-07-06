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

ll ans = 0;

void calc(int n, vector<ll> a) {
    if (n == 1) {
        ans = max(ans, a[0]);
        return;
    }
    vector<ll> tmp;
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        tmp.push_back(a[i] - a[i-1]);
        sum += tmp.back();
    }
    ans = max({ans, sum, -sum});
    calc(n-1, tmp);
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    ans = accumulate(all(a), 1ll*0);
    calc(n, a);
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

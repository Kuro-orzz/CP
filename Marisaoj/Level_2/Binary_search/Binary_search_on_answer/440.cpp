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

bool check(vector<int> &v, vector<int> &w, double mid, int k) {
    int n = v.size();
    vector<double> a;
    for (int i = 0; i < n; i++) a.push_back(v[i] - mid * w[i]);
    sort(all(a), greater<double>());
    double val = 0;
    for (int i = 0; i < k; i++) val += a[i];
    return val >= 0;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    double l = 0, r = 1e9;
    while (r - l > 1e-4) {
        double mid = (l + r) / 2;
        if (check(v, w, mid, k)) {
            l = mid;
        } else r = mid;
    }
    cout << fixed << setprecision(3) << l;
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
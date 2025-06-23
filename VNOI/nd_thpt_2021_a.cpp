/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "ghh"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

vector<int> sumDivisor_sieve(int n) {
    vector<int> v(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            v[j] += i;
        }
    }
    return v;
}

void solve() {
    vector<int> k = sumDivisor_sieve(1e6);
    int n; cin >> n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (2 * x <= k[x]) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << "\n";
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

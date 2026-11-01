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

vector<int> sieve(int n) {
    vector<int> nt(n+1, 1);
    nt[0] = nt[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!nt[i]) continue;
        for (int j = i * i; j <= n; j += i)
            nt[j] = 0;
    }
    return nt;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> prime = sieve(n);
    vector<int> a;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) a.push_back(i);
    }
    ll ans = 0, pos = 0;
    if (k > a.size()) {
        cout << ans << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i > a[pos]) pos++;
        if (pos > (int)a.size()-k) break;
        ans += n - a[pos+k-1] + 1;
    }
    cout << ans << '\n';
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
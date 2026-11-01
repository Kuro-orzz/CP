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
    int t; cin >> t;
    vector<int> prime = sieve(1e7);
    vector<int> a;
    for (int i = 0; i < prime.size(); i++) {
        if (prime[i]) a.push_back(i);
    }
    vector<vector<unsigned ll>> calc(11, vector<unsigned ll>(1, 1));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 3; j <= 10; j++) {
            if (i < j) calc[j].back() *= a[i];
            else if (calc[j].size() == i - j + 1 && ULLONG_MAX / (calc[j].back() / a[i-j]) > a[i]) {
                calc[j].push_back(calc[j].back() / a[i-j] * a[i]);
            } 
        }
    }
    while (t--) {
        unsigned ll n, k; cin >> n >> k;
        auto it = upper_bound(all(calc[k]), n) - calc[k].begin();
        if (!it) cout << "-1\n";
        else {
            cout << calc[k][it-1] << '\n';
        }
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
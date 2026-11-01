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

vector<vector<int>> sieve_prime_divisors(int n) {
    vector<int> prime = sieve(n);
    vector<vector<int>> div(n+1);
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = i; j <= n; j += i) {
            div[j].push_back(i);
        }
    }
    return div;
}

void solve() {
    int maxn = 1e6+1;
    int q; cin >> q;
    vector<vector<int>> prime_divisors = sieve_prime_divisors(maxn);
    vector<vector<int>> pref(maxn, vector<int>(8, 0));
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j <= 7; j++) {
            if (prime_divisors[i].size() == j) {
                pref[i][j] = pref[i-1][j] + 1;
            } else {
                pref[i][j] = pref[i-1][j];
            }
        }
    }
    while (q--) {
        int a, b, k; cin >> a >> b >> k;
        cout << pref[b][k] - pref[a-1][k] << '\n';
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
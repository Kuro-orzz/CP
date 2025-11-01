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

vector<int> sieve_prime(int n) {
    vector<int> nt(n+1, 1);
    nt[0] = nt[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!nt[i]) continue;
        for (int j = i * i; j <= n; j += i)
            nt[j] = 0;
    }
    return nt;
}

vector<vector<int>> sieve_divisors(int n) {
    vector<int> prime = sieve_prime(n);
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
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> sieve = sieve_divisors(1e6);

    vector<int> ans(n+1, INT_MAX);
    vector<int> lp(1000006);
    for (int i = 1; i <= n; i++) {
        for (int x : sieve[a[i]]) {
            if (lp[x]) {
                if (abs(lp[x] - ans[lp[x]]) > abs(lp[x] - i)) {
                    ans[lp[x]] = i;
                }
                if (abs(i - ans[i]) > abs(lp[x] - i)) {
                    ans[i] = lp[x];
                }
            }
            lp[x] = i;
        }
    }
    lp.assign(1000006, 0);
    for (int i = n; i >= 1; i--) {
        for (int x : sieve[a[i]]) {
            if (lp[x]) {
                if (abs(lp[x] - ans[lp[x]]) > abs(lp[x] - i)) {
                    ans[lp[x]] = i;
                }
                if (abs(i - ans[i]) > abs(lp[x] - i)) {
                    ans[i] = lp[x];
                }
            }
            lp[x] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << ' ';
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
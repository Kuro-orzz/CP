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

ll cnt[1000006];

// idea:
// - a[i] = x^2 * y
// - a[j] = u^2 * v
// => if y = v then a[i] * a[j] la chinh phuong
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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> sieve = sieve_divisors(1e6);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int p = 1;
        int tmp = a[i];
        for (int x : sieve[a[i]]) {
            int cnt = 0;
            while (tmp % x == 0) {
                cnt++;
                tmp /= x;
            }
            if (cnt % 2) p *= x;
        }
        if (tmp > 1) p *= tmp;
        ans += cnt[p];
        cnt[p]++;
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
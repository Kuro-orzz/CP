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
    vector<int> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j+=i) {
            isPrime[j] = 0;
        }
    }
    return isPrime;
}

int sumDigit(int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> isPrime = sieve(1e6);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = sumDigit(a[i]);
        if (isPrime[a[i]] && isPrime[sum]) ans++;
    }
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
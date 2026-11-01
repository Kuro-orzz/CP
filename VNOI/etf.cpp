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

ll eulerPhi(ll n) {
    if (n == 0) return 0;
    ll ans = n;
    for (ll p : {2, 3}) {
        if (n % p == 0) { 
            ans -= ans/p;
            while (n % p == 0) n /= p;
        }
    }
    for (ll i = 5; i*i <= n; i += 6) {
        if (n % i == 0) { 
            ans -= ans/i; 
            while (n % i == 0) n /= i;
        }
        if (n % (i+2)==0) {
            ans -= ans/(i+2);
            while (n % (i+2) == 0) n /= (i+2);
        }
    }
    if (n > 1) ans -= ans/n;
    return ans;
}

void solve() {
    int n; cin >> n;
    cout << eulerPhi(n) << '\n';
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
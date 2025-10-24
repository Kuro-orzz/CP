/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define mod (ll)(998244353)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

ll eulerPhi(ll n) {
    if (n == 0) return 0;
    ll ans = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ans -= ans / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

vector<int> phi_from_1_to_n(int n) {
    vector<int> phi(n + 1);
    iota(all(phi), 0);
    
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

// phi(a * b) = phi(a) * phi(b) * d / phi(d)
void solve() {
    int a, b; cin >> a >> b;
    vector<int> phi = phi_from_1_to_n(5e6);
    ll ans = 0;
    for (int i = 1; i <= b; i++) {
        int gcd = __gcd(i, a);
        int val = (1ull * phi[a] * phi[i] / phi[gcd] * gcd) % mod;
        ans = (ans + val) % mod;
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

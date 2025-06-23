/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "sdb"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

vector<int> segmentSieve(int l, int r){
    vector<int> prime(r-l+1, 1);
    for(ll p = 2; p*p <= r; p++){
        ll lim = max(p*p, (l+p-1)/p*p);
        for(ll j = lim; j <= r; j += p)
            if (j-l >= 0) prime[j-l] = 0;
    }
    if (l == 0) prime[0] = 0;
    if (l == 0 && r > l) prime[1] = 0;
    if (l == 1) prime[1-l] = 0;
    return prime;
}

vector<ll> listPrime(int l, int r) {
    vector<int> prime = segmentSieve(l, r);
    vector<ll> listPi;
    for (int i = l; i <= r; i++) {
        if (prime[i-l]) listPi.push_back(1ll*i*i);
    }
    return listPi;
}

bool isSqrt(int x) { return (int)sqrt(x) == sqrt(x); }

void solve() {
    vector<ll> sqrtPrime = listPrime(1, 1e5);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cout << *lower_bound(all(sqrtPrime), x) << ' ';
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

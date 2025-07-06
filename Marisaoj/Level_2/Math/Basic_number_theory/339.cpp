#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

using u128 = __uint128_t;

ll binPow(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while (b) {
        if (b & 1) res = (u128)res * a % M;
        a = (u128)a * a % M;
        b /= 2;
    }
    return res;
}

bool test(ll a, ll n, ll k, ll m) {
    ll mod = binPow(a, m, n);
    if (mod == 1 || mod == n - 1) return true;
    for (int l = 1; l < k; l++) {
        mod = (u128)mod * mod % n;
        if (mod == n - 1) return true;
    }
    return false;
}

bool MillerRabin(ll n) {
    if (n <= 1) return false;
    ll k = 0, m = n-1;
    while (m % 2 == 0) {
        m /= 2;
        k++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (!test(a, n, k, m)) return false;
    }
    return true;
}

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

vector<int> listPrime(int l, int r) {
    vector<int> prime = segmentSieve(l, r);
    vector<int> listPi;
    for (int i = l; i <= r; i++) {
        if (prime[i-l]) listPi.push_back(i);
    }
    return listPi;
}

int count_divisor(ll n, vector<int> &prime) {
    if (n == 1) return 1;
    int ans = 1;
    for (int p : prime) {
        if (1ll * p * p * p > n) break;
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        ans *= cnt + 1;
    }
    auto isSqrt = [&](ll n)->bool {
        ll c = sqrtl(n);
        return c * c == n;
    };
    if (n == 1) return ans;
    if (MillerRabin(n)) ans *= 2;
    else if (isSqrt(n)) ans *= 3;
    else ans *= 4;
    return ans;
}

vector<int> divisor;

void sieve_divisors(int n) {
    divisor.resize(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisor[j]++;
        }
    }
}

void solve() {
    int q; cin >> q;
    sieve_divisors(1e6);
    vector<int> prime = listPrime(1, 1e6+5);
    while(q--){
        int x; cin >> x;
        if (x <= 1e6) cout << divisor[x] << '\n';
        else cout << count_divisor(x, prime) << '\n';
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

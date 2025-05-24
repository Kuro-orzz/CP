#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll n, q, l, r;
vector<ll> prime, dp;

void init() {
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            prime.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) prime.push_back(n);
}

void solve() {
    cin >> n >> q;
    init();
    int t = prime.size();
    while(q--){
        cin >> l >> r;
        dp.clear();
        dp.resize(1 << t, 0);
        dp[0] = 1;
        ll ans = 0;
        for(int i = 1; i < (1 << t); i++){
            ll bit = __lg(i & -i);
            dp[i] = dp[i^(1 << bit)] * prime[bit];
            int sign = __builtin_popcount(i) & 1 ? 1 : -1; 
            ans += r/dp[i] * sign;
            ans -= (l-1)/dp[i] * sign;
        }
        cout << r-l+1-ans << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
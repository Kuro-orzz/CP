#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

bool checkPrime(ll n){
    for(ll i = 2; i*i <= n; i++)
        if(n % i == 0)
            return false;
    return n > 1;
}

vector<int> nt;
const int maxn = 1e6+6;

void sieve(){
    nt.resize(maxn, 0);
    for(int i = 1; i*i < maxn; i++){
        for(int j = i; j < maxn; j += i)
            if(i <= j/i) nt[j] += 2;
        nt[i*i]--;
    }
}

void solve() {
    sieve();
    vector<ll> pre(1e6+1, 0);
    for(int i = 1; i < pre.size(); i++)
        pre[i] = pre[i-1] + nt[i];
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << pre[r]-pre[l-1] << '\n';
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
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

vector<vector<int>> nt;
const int maxn = 1e6+6;

void sieve(){
    nt.resize(maxn);
    for(int i = 2; i < maxn; i++){
        if(nt[i].size() != 0) continue;
        for(int j = i; j < maxn; j += i)
            nt[j].push_back(i);
    }
}

void solve() {
    int n; cin >> n;
    for(int x : nt[n]) 
        cout << x << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    sieve();
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi firmn
#define se second

ll binpow(int a, int b, int c){
    if(b == 0) return 1;
    ll x = binpow(a, b/2, c);
    if(b%2) return x*x*a%c;
    return x*x%c;
}

void solve(){
    int a, b, c; cin >> a >> b >> c;
    cout << binpow(a, b, c);
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
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int q;

void solve(){
    cin >> q;
    bitset<32> b(0);
    while(q--){
        int tv, x; cin >> tv >> x;
        if(tv == 1) b[x] = 1;
        else if(tv == 2) b[x] = 0;
        else b[x] = b[x] ^ 1;
        cout << b.to_ulong() << '\n';
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
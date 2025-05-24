#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int q, a = 0;

void solve(){
    cin >> q;
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int x; cin >> x;
            a ^= x;
        }
        else if(tv == 2){
            int pos = 31-__builtin_clz(a);
            a &= ((1 << pos) -1);
        }
        else{
            cout << __builtin_popcountll(a) << '\n';
        }
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
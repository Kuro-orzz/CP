// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_mnatimnics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi firmn
#define se second

void solve(){
    int a, b, c; cin >> a >> b >> c;
    int x, y, z; cin >> x >> y >> z;
    if(c < z)
        cout << 1;
    else if(c > z)
        cout << 2;
    else if(b < y)
        cout << 1;
    else if(b > y)
        cout << 2;
    else if(a < x)
        cout << 1;
    else
        cout << 2;
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
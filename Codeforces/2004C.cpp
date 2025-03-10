// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    ll alice = 0;
    ll bob = 0;
    int c = 1;
    for(int i = n-1; i >= 0; i--){
        if(c)
            alice += a[i];
        else{
            int t = min(a[i+1]-a[i], k);
            a[i] += t;
            k -= t;
            bob += a[i];
        }
        c ^= 1;
    }
    cout << alice-bob << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
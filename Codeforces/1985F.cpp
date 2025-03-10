// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    ll h, n; cin >> h >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vi c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    ll l = 0, r = 40000000000;
    ll ans = 40000000000;
    while(l+1 < r){
        ll mid = (r+l)/2;
        ll t = 0;
        for(int i = 0; i < n; i++){
            t += ((mid-1)/c[i]+1)*a[i];
            t = min(t, h);
        }
        if(t >= h){
            ans = min(ans, mid);
            r = mid;
        }
        else
            l = mid;
    } 
    cout << ans << '\n';
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
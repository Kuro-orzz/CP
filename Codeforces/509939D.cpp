// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD (int)(1e9+7)
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define MASK64(x) (1LL << (x))

void solve(){
    int n; cin >> n;
    pii a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a, a+n);
    int ans = a[0].se-a[0].fi;
    pii tmp = {a[0].fi, a[0].se}; // begin, end
    for(int i = 1; i < n; i++){
        if(tmp.se >= a[i].fi)
            tmp.se = max(tmp.se, a[i].se);
        else
            tmp = a[i];
        ans = max(ans, tmp.se-tmp.fi);
    }
    cout << ans;
}   

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    cin.exceptions(cin.failbit);
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
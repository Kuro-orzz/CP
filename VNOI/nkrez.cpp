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
#define maxn 30006

pii p[maxn];
vi endAt[maxn];
vi dp(maxn+1, 0);

void solve(){
    int n; cin >> n;
    int k = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i].fi >> p[i].se;
        endAt[p[i].se].pb(i);
        k = max(k, p[i].se);
    }
    for(int i = 1; i <= maxn; i++){
        dp[i] = dp[i-1];
        for(int x : endAt[i]){
            dp[i] = max(dp[i], dp[p[x].fi]+p[x].se-p[x].fi);
        }
    }
    cout << dp[maxn];
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

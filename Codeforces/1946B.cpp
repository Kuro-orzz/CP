// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006
#define MASK64(x) (1LL << (x))
#define tuple64 tuple<ll, int, int>

void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll sum = 0;
    ll max_sum = a[0];
    ll cal_sum = 0;
    for(int i = 0; i < n; i++){
        sum = max(1ll*0, sum+1ll*a[i]);
        max_sum = max(max_sum, sum);
        cal_sum += a[i];
    }
    ll ans = (((cal_sum%MOD)+MOD)%MOD+max_sum)%MOD;
    for(int i = 0; i < k-1; i++){
        max_sum = (max_sum*2)%MOD;
        ans = (ans+max_sum)%MOD;
    }
    cout << ans << '\n';
}   
 
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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

 
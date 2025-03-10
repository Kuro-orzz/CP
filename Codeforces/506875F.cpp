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
#define maxn 500006

int a[maxn];

void solve(){
    int n; cin >> n;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    int cnt = 0;
    for(auto it : mp){
        if(it.se == 2)
            ans += cnt;
        else if(it.se > 2)
            ans += cnt*it.se*(it.se-1)/2 + it.se*(it.se-1)*(it.se-2)/6;
        cnt += it.se;
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
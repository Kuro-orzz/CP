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
#define maxn 1000006
#define MASK64(x) (1LL << (x))

int a[maxn], prefix[maxn];

void solve(){
    int n; cin >> n;
    prefix[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        prefix[i+1] = prefix[i]+a[i];
    }
    int ans = 0;
    int sum = INF;
    for(int i = 1; i < n; i++){
        int T1 = prefix[i];
        int T2 = prefix[n]-T1;
        if(abs(T2-T1) < sum){
            sum = abs(T2-T1);
            ans = i;
        }
    }
    cout << ans;
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
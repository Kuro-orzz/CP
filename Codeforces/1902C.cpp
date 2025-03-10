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
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    int tmp = a[1]-a[0];
    for(int i = 2; i < n; i++)
        tmp = __gcd(tmp, a[i]-a[i-1]);
    if((a[n-1]-a[0])/tmp+1 == n)
        cout << 1ll*n*(1+n)/2 << '\n';
    else{
        ll ans = 0;
        for(int i = 0; i < n-1; i++)
            ans += (a[n-1]-a[i])/tmp;
        for(int i = 1; i < n; i++){
            if(a[n-i]-a[n-i-1] != tmp){
                ans += (a[n-1]-(a[n-i]-tmp))/tmp;
                break;
            }
        }
        cout << ans << '\n';
    }
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
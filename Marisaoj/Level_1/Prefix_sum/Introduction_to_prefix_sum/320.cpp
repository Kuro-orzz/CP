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
    int n, q; cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll pre[n+1];
    pre[0] = 0;
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i-1]+a[i-1];
    ll cal[n+1];
    cal[0] = 0;
    for(int i = 1; i <= n; i++)
        cal[i] = cal[i-1]+1ll*a[i-1]*i;
    while(q--){
        int l, r; cin >> l >> r;
        ll ans = cal[r]-cal[l-1]-(pre[r]-pre[l-1])*(l-1);
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
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
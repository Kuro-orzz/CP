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
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(all(a));
    pii cur = a[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(cur.fi <= a[i].fi && cur.se >= a[i].se)
            cur = a[i];
        else if(cur.se >= a[i].fi && cur.se <= a[i].se)
            continue;
        else{
            cur = a[i];
            ans++;
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
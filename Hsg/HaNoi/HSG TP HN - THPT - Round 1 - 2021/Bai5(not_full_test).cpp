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
    int n, m; cin >> n >> m;
    vector<pii> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i].fi;
    for(int i = 0; i < n; i++) cin >> a[i].se;
    for(int i = 0; i < m; i++) cin >> b[i].fi;
    for(int i = 0; i < m; i++) cin >> b[i].se;


}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("GH.INP", "r", stdin);
    freopen("GH.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

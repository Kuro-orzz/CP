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
    vector<pii> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    vector<pii> b = a;
    sort(all(b));
    vector<pii> c(n);
    for(int i = 0; i < n; i++)
        c[i] = {m-a[i].se, m-a[i].fi};
    sort(all(c));
    for(int i = 0; i < n; i++){
        auto ub1 = upper_bound(all(b), make_pair(a[i].se, INT_MAX));
        auto lb1 = upper_bound(all(b), a[i]);
        auto ub2 = upper_bound(all(c), make_pair(m-a[i].fi, INT_MAX));
        auto lb2 = upper_bound(all(c), make_pair(m-a[i].se, m-a[i].fi));
        cout << ub1-lb1+ub2-lb2 << '\n';
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

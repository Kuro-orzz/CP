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
    vi a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    vector<pii> Q(q);
    for(int i = 0; i < q; i++)
        cin >> Q[i].fi >> Q[i].se;
    for(int i = q-1; i >= 0; i--)
        swap(a[Q[i].fi-1], a[Q[i].se-1]);
    for(int x : a)
        cout << x << " ";
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
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e5+6;
int n, f[maxn], mxDoor[maxn];
vector<pii> a;

void solve(){
    cin >> n;
    a.resize(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se;
    sort(a.begin()+1, a.begin()+n+1, greater<pii>());
    f[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i-1], a[i].se-a[i].fi);
    }
    mxDoor[n+1] = -1e9;
    for (int i = n; i >= 1; i--) {
        mxDoor[i] = max(mxDoor[i+1], a[i].se);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i].fi;
        cout << max(ans+f[i], ans-a[i].fi+mxDoor[i]) << '\n';
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
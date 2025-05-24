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
int n, m, q;
pii a[maxn], query[maxn];
ll pref[maxn], ans[maxn];

void solve(){
    cin >> n >> q >> m;
    for (int i = 1; i <= q; i++) 
        cin >> a[i].fi >> a[i].se;
    for (int i = 1; i <= m; i++)
        cin >> query[i].fi >> query[i].se;
    for (int i = 1; i <= m; i++) {
        pref[query[i].fi]++; 
        pref[query[i].se+1]--;
    }
    for (int i = 1; i <= q; i++)
        pref[i] += pref[i-1];
    for (int i = 1; i <= q; i++) {
        ans[a[i].fi] += pref[i];
        ans[a[i].se+1] -= pref[i];
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << ' ';
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
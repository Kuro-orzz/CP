#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e3+6;
int n;
pii t;
vector<pii> a, val;
map<pair<ll, ll>, int> mp;

void MITM(int i, pair<ll, ll> cur, int end) {
    if (i >= end) val.push_back(cur);
    else {
        MITM(i+1, cur, end);
        MITM(i+1, {cur.fi+a[i].fi, cur.se+a[i].se}, end);
    }
}

void solve() {
    cin >> n >> t.fi >> t.se;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].fi >> a[i].se;
    MITM(0, {0, 0}, n/2);
    for (auto it : val) mp[it]++;
    val.clear();
    MITM(n/2, {0, 0}, n);
    ll ans = 0;
    for (int i = 0; i < val.size(); i++) {
        pair<ll, ll> x = {t.fi-val[i].fi, t.se-val[i].se};
        if (!mp.count(x)) continue;
        ans += mp[x];
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
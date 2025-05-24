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

int n, q;
pii a[maxn];
vector<pair<int, ll>> pre;

int bs(int l, int r, ll x){
    int res = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(pre[mid].se >= x){
            res = mid;
            r = mid-1;
        }
        else if(pre[mid].se < x) l = mid+1;
    }
    return res;
}

void solve(){
    cin >> n >> q;
    pre.resize(maxn, {0, 0});
    for(int i = 1; i <= n; i++)
        cin >> a[i].se >> a[i].fi;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
        pre[i] = {a[i].fi, pre[i-1].se+a[i].se};
    while(q--){
        ll x; cin >> x;
        cout << pre[bs(1, n, x)].fi << '\n';
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
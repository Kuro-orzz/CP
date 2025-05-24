#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int N = 1e5+6;
ll a[N], st[4*N];

void update(int id, int l, int r, int pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        a[l] = val;
        st[id] = val;
        return;
    }
    int mid = (l+r) >> 1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = min(st[id*2], st[id*2+1]);
}

ll getMin(int id, int l, int r, int u, int v){
    if(r < u || l > v)
        return LLONG_MAX;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r) >> 1;
    ll t1 = getMin(id*2, l, mid, u, v);
    ll t2 = getMin(id*2+1, mid+1, r, u, v);
    return min(t1, t2); 
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];    
        update(1, 1, n, i, a[i]);
    }
    while(q--){
        ll tv, u, v; cin >> tv >> u >> v;
        if(tv == 1)
            update(1, 1, n, u, a[u]+v);
        else
            cout << getMin(1, 1, n, u, v) << '\n';
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
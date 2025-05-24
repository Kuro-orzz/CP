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
ll st[4*N], lazy[4*N];

void push(int id, int l, int r){
    int mid = (l+r) >> 1;
    st[id*2] += lazy[id] * (mid-l+1);
    st[id*2+1] += lazy[id] * (r-mid);
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0; 
}

void update(int id, int l, int r, int u, int v, ll val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        st[id] += val * (r - l + 1);
        lazy[id] += val;
        return;
    }
    push(id, l, r);
    int mid = (l+r) >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = st[id*2] + st[id*2+1];
}

ll getSum(int id, int l, int r, int u, int v){
    if(r < u || v < l)
        return 0;
    if(u <= l && r <= v)
        return st[id];
    push(id, l, r);
    int mid = (l+r) >> 1;
    ll t1 = getSum(id*2, l, mid, u, v);
    ll t2 = getSum(id*2+1, mid+1, r, u, v);
    return t1 + t2; 
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;    
        update(1, 1, n, i, i, x);
    }
    while(q--){
        int tv, u, v; cin >> tv >> u >> v;
        if(tv == 1){
            int x; cin >> x;
            update(1, 1, n, u, v, x);
        }
        else
            cout << getSum(1, 1, n, u, v) << '\n';
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
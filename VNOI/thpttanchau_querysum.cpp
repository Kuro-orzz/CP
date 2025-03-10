// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006
 
ll a[maxn], st[4*maxn], lazy[4*maxn];
 
void build(int id, int l, int r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2]+st[id*2+1];
}

void push(int id, int sz){
    if(lazy[id]){
        int sz1, sz2;
        if(sz % 2 == 0)
            sz1 = sz2 = sz/2;
        else{
            sz1 = sz/2+1;
            sz2 = sz/2;
        }
        st[id*2] += lazy[id]*sz1;
        st[id*2+1] += lazy[id]*sz2;
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, ll val){
    if(u > r || v < l)
        return;
    if(u <= l && v >= r){
        st[id] += val*(r-l+1);
        lazy[id] += val;
        return;
    }
    push(id, r-l+1);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = st[id*2]+st[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return 0;
    if(u <= l && v >= r)
        return st[id];
    push(id, r-l+1);
    int mid = (l+r)>>1;
    return get(id*2, l, mid, u, v)+get(id*2+1, mid+1, r, u, v);
}
 
void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(q--){
        int tv, u, v; cin >> tv >> u >> v;
        if(tv == 1){
            ll x; cin >> x;
            update(1, 1, n, u, v, x);
        }
        else
            cout << get(1, 1, n, u, v) << '\n';
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

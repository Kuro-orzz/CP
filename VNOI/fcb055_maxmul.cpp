// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006

ll a[maxn], st[4*maxn];

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l) return 1;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)>>1;
    return get(id*2, l, mid, u, v)*get(id*2+1, mid+1, r, u, v)%MOD;
}

void update(int id, int l, int r, int pos, int val){
    if(l > pos || r < pos)
        return;
    if(l == r){
        a[pos] = val;
        st[id] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = st[id*2]*st[id*2+1]%MOD;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, l+r-1) << '\n';
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

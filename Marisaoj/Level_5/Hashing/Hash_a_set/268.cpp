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

ll mn[4*maxn], mx[4*maxn], lazy[4*maxn];

void push(int id){
    if(lazy[id]){
        mn[id*2] += lazy[id];
        mn[id*2+1] += lazy[id];
        mx[id*2] += lazy[id];
        mx[id*2+1] += lazy[id];
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, ll val){
    if(u > r || v < l) return;
    if(u <= l && v >= r){
        mn[id] += val;
        mx[id] += val;
        lazy[id] += val;
        return;
    }
    push(id);
    int mid = (l+r)>>1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    mn[id] = min(mn[id*2], mn[id*2+1]);
    mx[id] = max(mx[id*2], mx[id*2+1]);
}

ll getMin(int id, int l, int r, int u, int v){
    if(u > r || v < l) return LLONG_MAX;
    if(u <= l && v >= r) return mn[id];
    push(id);
    int mid = (l+r)>>1;
    return min(getMin(id*2, l, mid, u, v), getMin(id*2+1, mid+1, r, u, v));
}

ll getMax(int id, int l, int r, int u, int v){
    if(u > r || v < l) return 0;
    if(u <= l && v >= r) return mx[id];
    push(id);
    int mid = (l+r)>>1;
    return max(getMax(id*2, l, mid, u, v), getMax(id*2+1, mid+1, r, u, v));
}

void solve(){
    int n, q; cin >> n >> q;
    mt19937 rng(time(NULL));
    vector<ll> H(maxn);
    for(int i = 0; i < maxn; i++)
        H[i] = rng();
    while(q--){
        int tv, l, r; cin >> tv >> l >> r;
        if(tv == 1){
            int x; cin >> x; 
            update(1, 1, n, l, r, H[x]);
        }
        else{
            if(getMin(1, 1, n, l, r) == getMax(1, 1, n, l, r))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
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
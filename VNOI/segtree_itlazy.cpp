// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e7
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 100006

int n, q, a[maxn];
ll st[4*maxn], lazy[4*maxn];

void push(int id){
    if(lazy[id]){
        st[id*2] += lazy[id];
        st[id*2+1] += lazy[id];
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
        lazy[id] = 0;
    }
}

ll get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return INT_MIN;
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)/2;
    push(id);
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || u > r)
        return;
    if(u <= l && v >= r){
        st[id] += val;
        lazy[id] += val;
        return; 
    }
    int mid = (l+r)/2;
    push(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id] = max(st[id*2], st[id*2+1]);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        update(1, 1, n, i, i, x);
    }
    memset(lazy, 0, sizeof(lazy));
    cin >> q;
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int x, y, val; cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }
        else{
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

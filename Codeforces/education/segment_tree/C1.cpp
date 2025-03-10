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
#define maxn 200006

struct Node{
    int val, cnt;
};

int a[maxn], n, q;
Node st[4*maxn];

void build(int id, int l, int r){
    if(l == r){
        st[id].val = a[l];
        st[id].cnt = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].val = min(st[id*2].val, st[id*2+1].val);
    if(st[id*2].val == st[id*2+1].val)
        st[id].cnt = st[id*2].cnt+st[id*2+1].cnt;
    else
        if(st[id].val == st[id*2].val)
            st[id].cnt = st[id*2].cnt;
        else
            st[id].cnt = st[id*2+1].cnt;
}

pii get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return {INF, INF};
    if(u <= l && v >= r)
        return {st[id].val, st[id].cnt};
    int mid = (l+r)/2;
    pii t1 = get(id*2, l, mid, u, v);
    pii t2 = get(id*2+1, mid+1, r, u, v);
    if(t1.fi == t2.fi)
        return {t1.fi, t1.se+t2.se};
    else{
        if(t1.fi < t2.fi)
            return t1;
        else
            return t2;
    }
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || pos > r)
        return;
    if(l == r){
        st[id].val = val;
        st[id].cnt = 1;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id].val = min(st[id*2].val, st[id*2+1].val);
    if(st[id*2].val == st[id*2+1].val)
        st[id].cnt = st[id*2].cnt+st[id*2+1].cnt;
    else
        if(st[id].val == st[id*2].val)
            st[id].cnt = st[id*2].cnt;
        else
            st[id].cnt = st[id*2+1].cnt;
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // update(1, 1, n, i, a[i]);
    }
    build(1, 1, n);
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int pos, val; cin >> pos >> val;
            update(1, 1, n, pos+1, val);
            a[pos+1] = val;
        }
        else{
            int l, r; cin >> l >> r;
            pii ans = get(1, 1, n, l+1, r);
            cout << ans.fi << " " << ans.se << '\n'; 
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

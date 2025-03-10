#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct Node{
    ll sum, pre, suf, ans;
};

const int maxn = 2e5+1;
ll a[maxn];
Node st[4*maxn];

Node merge(Node u, Node v){
    Node res;
    res.ans = max({u.ans, v.ans, u.suf+v.pre});
    res.sum = u.sum+v.sum;
    res.pre = max({u.pre, u.sum+v.pre});
    res.suf = max({v.suf, v.sum+u.suf});
    return res;
}

void update(int id, int l, int r, int pos, int val){
    if(l > pos || r < pos)
        return;
    if(l == r){
        st[id] = {val, max(val, 0), max(val, 0), max(val, 0)};
        return; 
    }
    int mid = (l+r)>>1;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = merge(st[id*2], st[id*2+1]);
}

Node get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return {1, 1};
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)>>1;
    return merge(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while(q--){
        int k, x; cin >> k >> x;
        update(1, 1, n, k, x);
        cout << st[1].ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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
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
    ll sum, pre, suf, maxsum;
};

int n, q, a[maxn];
Node st[4*maxn];

Node Merge(Node &a, Node &b){
    Node ans;
    ans.pre = max(a.pre, a.sum+b.pre);
    ans.suf = max(b.suf, a.suf+b.sum);
    ans.sum = a.sum+b.sum;
    ans.maxsum = max({a.maxsum, b.maxsum, a.suf+b.pre});
    return ans;
}

Node get(int id, int l, int r, int u, int v){
    if(u > r || v < l)
        return {-INF, -INF, 0, -INF};
    if(u <= l && v >= r)
        return st[id];
    int mid = (l+r)/2;
    Node t1 = get(id*2, l, mid, u, v);
    Node t2 = get(id*2+1, mid+1, r, u, v);
    return Merge(t1, t2);
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || pos > r)
        return;
    if(l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    st[id] = Merge(st[id*2], st[id*2+1]);
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        Node ans = get(1, 1, n, u, v);
        cout << ans.maxsum << endl;
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

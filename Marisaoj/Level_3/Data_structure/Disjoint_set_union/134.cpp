// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 100006

struct Dsu {
    vector<int> par, sz;

    Dsu(int n): par(n), sz(n, 1){
        for(int i = 0; i < par.size(); i++)
            par[i] = i;
    }
    
    int find(int v){
        if(v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w){
        u = _u; v = _v; w = _w;
    };
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void solve(){
    int n, q; cin >> n >> q;
    Dsu g(n+1);
    vector<Edge> a;
    for(int i = 0; i < q; i++){
        int u, v, w; cin >> u >> v >> w;
        a.push_back(Edge(u, v, w));
    }
    sort(all(a), cmp);
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(g.find(a[i].u) != g.find(a[i].v)){
            ans += a[i].w;
            g.merge(a[i].u, a[i].v);
        }
    }
    cout << ans;
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
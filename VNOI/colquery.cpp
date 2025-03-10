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

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006

struct dsu{
    vector<map<int, int>> color;
    vi par, sz;
    dsu(int n): par(n), sz(n), color(n) {};
    void make_set(){
        for(int i = 0; i < par.size(); i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int v){
        if(v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a] < sz[b]) swap(a, b);
            sz[a] += sz[b];
            par[b] = a;
            for(auto it : color[b])
                color[a][it.fi] += it.se;
        }
    }
    int count_color(int u, int c){
        u = find(u);
        return color[u][c];
    }
};

void solve(){
    int n, q; cin >> n >> q;
    dsu g(n+2);
    g.make_set();
    vi a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        g.color[i][a[i]]++;
    }
    while(q--){
        int tv, u, v; cin >> tv >> u >> v;
        if(tv == 1){
            g.Union(u, v);
        }
        else{
            cout << g.count_color(u, v) << '\n';
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

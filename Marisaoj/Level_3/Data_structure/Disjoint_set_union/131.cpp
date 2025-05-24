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

struct dsu{
    vector<int> par, sz;
    dsu(int n): par(n), sz(n){
        for(int i = 0; i < par.size(); i++)
            par[i] = i, sz[i] = i;
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

void solve(){
    int n, q; cin >> n >> q;
    dsu g(n+1);
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int u, v; cin >> u >> v;
            g.merge(u, v);
        }
        else{
            int u; cin >> u;
            cout << g.sz[g.find(u)] << '\n';
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
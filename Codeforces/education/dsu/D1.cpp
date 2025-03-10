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
#define maxn 10006

struct dsu{
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1){
        for(int i = 0; i < par.size(); i++){
            par[i] = i;
        }
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
            par[b] = a;
            sz[a] += sz[b];
        }
    }
    bool ask(int u, int v){
        u = find(u);
        v = find(v);
        return u == v;
    }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    dsu g(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        // g.Union(u, v);
    }
    vector<pair<string, pii>> q;
    for(int i = 0; i < k; i++){
        string s; cin >> s;
        int u, v; cin >> u >> v;
        q.pb({s, {u, v}});
    }
    vi ans;
    for(int i = k-1; i >= 0; i--){
        if(q[i].fi == "cut"){
            g.Union(q[i].se.fi, q[i].se.se);
        }
        else{
            ans.pb(g.ask(q[i].se.fi, q[i].se.se));
        }
    }
    for(int i = ans.size()-1; i >= 0; i--){
        if(ans[i])
            cout << "YES\n";
        else
            cout << "NO\n";
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

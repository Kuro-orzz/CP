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
    vector<int> par, sz, max_ele, min_ele;
    dsu(int n): par(n), sz(n), max_ele(n), min_ele(n){
        for(int i = 0; i < par.size(); i++){
            par[i] = i;
            sz[i] = 1;
            max_ele[i] = i;
            min_ele[i] = i;
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
            max_ele[a] = max(max_ele[a], max_ele[b]);
            min_ele[a] = min(min_ele[a], min_ele[b]);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    dsu g(n+1);
    while(m--){
        string s; cin >> s;
        if(s == "union"){
            int a, b; cin >> a >> b;
            g.Union(a, b);
        }
        else{
            int u; cin >> u;
            u = g.find(u);
            cout << g.min_ele[u] << " " << g.max_ele[u] << " " << g.sz[u] << '\n';
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

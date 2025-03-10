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
    vector<int> par, sz, points;
    vector<unordered_set<int>> child;
    dsu(int n): par(n), sz(n, 1), points(n, 0), child(n){
        for(int i = 0; i < par.size(); i++){
            par[i] = i;
            child[i].insert(i);
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
            for(int x : child[b]){
                child[a].insert(x);
                if(x != b)
                    points[x] += points[b]-points[a];
            }
            points[b] -= points[a];
        }
    }
    void add(int u, int val){
        u = find(u);
        points[u] += val;
    }
    ll get_points(int u){
        int v = find(u);
        if(u == v)
            return points[u];
        else
            return points[v]+points[u];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    dsu g(n+1);
    while(m--){
        string s; cin >> s;
        if(s == "add"){
            int u, p; cin >> u >> p;
            g.add(u, p);
        }
        else if(s == "join"){
            int a, b; cin >> a >> b;
            g.Union(a, b);
        }
        else{
            int u; cin >> u;
            cout << g.get_points(u) << '\n';
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

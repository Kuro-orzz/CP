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

vi c;
vector<vi> adj;
int path = 0;
vi vis;

void dfs(int u, int cat, int m){
    vis[u] = 1;
    if(c[u])
        cat++;
    else
        cat = 0;
    if(cat > m)
        return;
    int child = 0;
    for(int v : adj[u])
        if(!vis[v]){
            dfs(v, cat, m);
            child++;
        }
    if(!child)
        path++;
}

void solve(){
    int n, m; cin >> n >> m;
    c.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.resize(n+1, 0);
    dfs(1, 0, m);
    cout << path;
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
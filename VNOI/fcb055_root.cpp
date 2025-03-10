#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct dsu{
    vector<int> par, sz;
    dsu(int n){
        par.resize(n+1);
        sz.resize(n+1, 1);
        for(int i = 1; i <= n; i++)
            par[i] = i;
    }
    int find(int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u != v){
            if(sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
} g(1e5);

vector<vector<int>> adj;
vector<int> vis;

void bfs(int u, int v){
    if(vis[v] || u == v) return;
    u = g.find(u);
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int k : adj[t]){
            if(!vis[k] && k != v){
                vis[k] = 1;
                q.push(k);
                g.merge(k, v);
            }
        }
    }
    g.merge(u, v);
}

void solve(){
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n+1, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        bfs(v, u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            ans++;
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

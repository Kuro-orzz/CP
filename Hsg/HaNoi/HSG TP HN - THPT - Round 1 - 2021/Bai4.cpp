#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<int>> adj;
vector<int> v;
vector<int> vis;
vector<int> diameter;
vector<int> d;
int ans = 0;

bool dfs(int u, int par, int end){
    if(u == end){
        diameter.push_back(u);
        vis[u] = 1;
        return true;
    }
    for(auto v : adj[u])
        if(v != par){
            if(dfs(v, u, end)){
                diameter.push_back(u);
                vis[u] = 1;
                return true;
            }
        }
    return false;
}

void dfs1(int u, int par, int k){
    vis[u] = 1;
    if(d[u] <= k) ans++;
    for(int v : adj[u]){
        if(v != par && !vis[v]){
            d[v] = d[u]+1;
            dfs1(v, u, k);
        }
    }
}

int bfs(int u, int n){
    queue<int> q;
    vector<int> vis(n+1, 0);
    vis[u] = 1;
    q.push(u);
    int res;
    while(!q.empty()){
        int k = q.front(); q.pop();
        if(v[k]) res = k;
        for(int x : adj[k]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return res;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    v.resize(n+1, 0);
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        v[x] = 1;
    }
    int start = bfs(1, n);
    int end = bfs(start, n);
    // cout << start << " " << end << '\n';
    vis.resize(n+1, 0);
    dfs(start, -1, end);
    // for(int x : diameter)
        // cout << x << " ";
    d.resize(n+1, 0);
    // for(int x : diameter)
    //     dfs1(x, -1);
    // for(int i = 0; i <= n; i++)
        // cout << i << ": " << d[i] << '\n';
    for(int i = 0; i < diameter.size(); i++){
        d[diameter[i]] = max((int)diameter.size()-i-1, i);
        dfs1(diameter[i], -1, k);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    freopen("BV.INP", "r", stdin);
    freopen("BV.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define pii pair<int, int>
#define fi first
#define se second

const int maxN = 10006;
int cnt = 0, bridge = 0, k = 0;
vector<int> vis(maxN, 0);
vector<int> id(maxN), low(maxN);
vector<int> adj[maxN];

void dfs(int u, int p){
    vis[u] = 1;
    id[u] = low[u] = ++cnt;
    int node = (p != 0);
    for(int v : adj[u]){
        if(v == p)
            continue;
        if(id[v])
            low[u] = min(low[u], id[v]);
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == id[v]) bridge++;
            if(low[v] >= id[u]) node++;
        }
    }
    if(node >= 2) k++;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i < n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    cout << k << " " << bridge;
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // int t; cin >> t;
    // while(t--)
        solve();
    return 0;
}

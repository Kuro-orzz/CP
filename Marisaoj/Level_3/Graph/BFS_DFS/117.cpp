#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<vector<int>> adj;
vector<int> vis, d, par;

void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    d[1] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int k : adj[v]){
            if(!vis[k]){
                if(d[k] > d[v]+1){
                    d[k] = min(d[k], d[v]+1);
                    par[k] = v;
                }
                vis[k] = 1;
                q.push(k);
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, 0);
    d.resize(n+1, INT_MAX);
    par.resize(n+1, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    bfs(1);
    cout << d[n] << '\n';
    vector<int> path;
    int t = n;
    while(t != 0){
        path.push_back(t);
        t = par[t];
    }
    reverse(all(path));
    for(int x : path)
        cout << x << " ";
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
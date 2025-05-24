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
vector<int> vis, color;

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int k : adj[v]){
            if(color[k] == color[v])
                return false;
            else if(!color[k]){
                if(color[v] == 1) color[k] = 2;
                else color[k] = 1;
                q.push(k);
            }
        }
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color.resize(n+1, 0);
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!bfs(i)){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
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
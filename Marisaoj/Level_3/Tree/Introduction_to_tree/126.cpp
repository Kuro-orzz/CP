#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
 
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
 
const int maxn = 1e5+6;
int n, m, vis[maxn];
vector<vector<int>> adj;

bool dfs(int u, int par = 0){
    vis[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        if(vis[v]) return false;
        bool t = dfs(v, u);
        if(!t) return false;
    }
    return true;
}

void solve(){
    cin >> n >> m;
    adj.resize(n+1);
    if(n != m+1){
        cout << "NO";
        return;
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(dfs(1)){
        cout << "YES";
    }
    else{
        cout << "NO";
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
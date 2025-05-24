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
int n, m, vis[maxn], sub[maxn];
vector<vector<int>> adj;
int ans = 0;

int dfs(int u, int par = 0){
    vis[u] = 1;
    int cnt = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        cnt += dfs(v, u);
    }
    return sub[u] = cnt;
}

void solve(){
    cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout << sub[i] << ' ';
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
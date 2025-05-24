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
int ans = 0;
bool root = false;

void dfs(int u, int par = 0){
    vis[u] = 1;
    int cnt = 0;
    for(int v : adj[u]){
        cnt++;
        if(v == par) continue;
        dfs(v, u);
    }
    if(cnt == 1) ans++;
    if(cnt > 1) root = true;
}

void solve(){
    cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 1 || n == 2){
        cout << 1;
        return;
    }
    dfs(1);
    if(!root) cout << ans-1;
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
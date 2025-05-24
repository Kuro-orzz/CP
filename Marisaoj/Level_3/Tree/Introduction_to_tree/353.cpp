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
int n, vis[maxn], color[maxn];
string s;
vector<vector<int>> adj;
int ans = 0;

void dfs(int u, int par = 0, int white = 0, int black = 0){
    vis[u] = 1;
    if(color[u] == 0) white++;
    else black++;
    if(white > black) ans++;
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u, white, black);
    }
}

void solve(){
    cin >> n >> s;
    adj.resize(n+1);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') color[i+1] = 0;
        else color[i+1] = 1;
    }
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
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
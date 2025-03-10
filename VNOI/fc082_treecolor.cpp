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
vector<int> color;
set<int> cnt[100001];
vector<int> ans;
void dfs(int u, int par){
    cnt[u].insert(color[u]);
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
        if(cnt[u].size() < cnt[v].size())
            cnt[u].swap(cnt[v]);
        for(int i : cnt[v])
            cnt[u].insert(i);
    }
    ans[u] = cnt[u].size();
}

void solve(){
    int n; cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    color.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    ans.resize(n+1);
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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

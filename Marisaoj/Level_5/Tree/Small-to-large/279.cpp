#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()
#define unique(x) x.erase(unique(all(x)), x.end())
#define inf (ll)1e18

#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

const int N = 1e5 + 6;
int n;
int color[N], ans[N];
vector<vector<int>> adj;
set<int> cnt[N];

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
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
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
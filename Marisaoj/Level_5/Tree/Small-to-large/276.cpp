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

const int maxn = 1e5+6;
vector<vector<int>> adj;
vector<int> a, ans;
multiset<int> s[maxn];
 
void dfs(int u, int par){
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
        if(s[u].size() < s[v].size())
            swap(s[u], s[v]);
        for(auto it : s[v])
            s[u].insert(it);
    }
    auto it = s[u].lower_bound(a[u]);
    if(it != s[u].end())
        s[u].erase(it);
    s[u].insert(a[u]);
    ans[u] = s[u].size();
}
 
void solve(){
    int n; cin >> n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    adj.resize(n+1);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans.resize(n+1);
    dfs(1, 0);
    cout << ans[1];
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
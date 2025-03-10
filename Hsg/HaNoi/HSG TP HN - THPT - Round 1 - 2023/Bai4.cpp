#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e5+6;
vector<vector<int>> adj;
vector<int> a, ans;
vector<int> s[maxn];

void dfs(int u, int par){
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v, u);
        if(s[u].size() < s[v].size())
            swap(s[u], s[v]);
        for(auto it : s[v])
            s[u].push_back(it);
    }
    sort(all(s[u]));
    auto it = lower_bound(s[u].begin(),s[u].end(),a[u]);
    if (it == s[u].end()) s[u].push_back(a[u]);
    else (*it) = min((*it),a[u]);
    ans[u] = s[u].size();
}

void solve(){
    int n, q; cin >> n >> q;
    a.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    adj.resize(n+1);
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    ans.resize(n+1);
    dfs(1, 0);
    while(q--){
        int u; cin >> u;
        cout << ans[u] << '\n';
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

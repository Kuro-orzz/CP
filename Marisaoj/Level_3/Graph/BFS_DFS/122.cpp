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

vector<vector<int>> adj;
vector<vector<int>> d;
 
void dijkstra(int u, int n){
    queue<pii> q;
    d[u][0] = 0; 
    q.push({u, 0});
    while(!q.empty()){
        auto [v, k] = q.front(); q.pop();
        for(int u : adj[v]){
            if (d[u][1-k] == 1e9) {
                d[u][1-k] = d[v][k] + 1;
                q.push({u, 1-k});
            }
        }
    }
}
 
void solve(){
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;
    adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d.resize(n+1, vector<int>(2, 1e9));
    dijkstra(a, n);
    if(d[b][0] == 1e9) cout << -1;
    else cout << d[b][0]/2;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
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
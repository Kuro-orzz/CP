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
vector<vector<pii>> adj(maxn);
vector<int> par(maxn, -1);
vector<ll> d(maxn, 1e18);

void dijkstra(int u, int n){
    vector<int> vis(n+1, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[u] = 0;
    pq.push({0, u});
    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        if(vis[u.se]) continue;
        vis[u.se] = 1;
        for(auto it : adj[u.se]){
            int v = it.fi;
            int w = it.se;
            if(d[v] > d[u.se] + w){
                d[v] = d[u.se] + w;
                par[v] = u.se;
                pq.push({d[v], v});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1, n);
    if(d[n] == 1e18){
        cout << -1;
        return;
    }
    cout << d[n] << '\n';
    vector<int> path;
    int v = n;
    while(v != -1){
        path.push_back(v);
        v = par[v];
    }
    reverse(all(path));
    for(ll x : path)
        cout << x << " ";
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
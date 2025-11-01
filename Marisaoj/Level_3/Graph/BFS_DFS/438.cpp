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
vector<int> d;

void dijkstra(int u, int n){
    vector<int> vis(n+1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[u], u});
    d[u] = 0;
    while(!pq.empty()){
        pii v = pq.top(); pq.pop();
        if(vis[v.se]) continue;
        vis[v.se] = 1;
        for(int k : adj[v.se]){
            if(d[k] > d[v.se]+1){
                d[k] = d[v.se]+1;
                pq.push({d[k], k});
            }
        }
    }
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> p(k);
    for(int i = 0; i < k; i++)
        cin >> p[i];
    adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d.resize(n+1, INT_MAX);
    dijkstra(n, n);
    for(int i = 0; i < k; i++)
        cout << d[p[i]] << ' ';
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
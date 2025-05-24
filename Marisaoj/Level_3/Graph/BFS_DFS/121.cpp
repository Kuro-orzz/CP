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
vector<int> d1, d2;

void dijkstra1(int u, int n){
    vector<int> vis(n+1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d1[u], u});
    d1[u] = 0;
    while(!pq.empty()){
        pii v = pq.top(); pq.pop();
        if(vis[v.se]) continue;
        vis[v.se] = 1;
        for(int k : adj[v.se]){
            if(d1[k] > d1[v.se]+1){
                d1[k] = d1[v.se]+1;
                pq.push({d1[k], k});
            }
        }
    }
}

void dijkstra2(int u, int n){
    vector<int> vis(n+1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d2[u], u});
    d2[u] = 0;
    while(!pq.empty()){
        pii v = pq.top(); pq.pop();
        if(vis[v.se]) continue;
        vis[v.se] = 1;
        for(int k : adj[v.se]){
            if(d2[k] > d2[v.se]+1){
                d2[k] = d2[v.se]+1;
                pq.push({d2[k], k});
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
    d1.resize(n+1, INT_MAX);
    d2.resize(n+1, INT_MAX);
    dijkstra1(a, n);
    dijkstra2(b, n);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(d1[i] <= d2[i])
            ans++;
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
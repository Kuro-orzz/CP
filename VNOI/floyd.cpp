// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006

int n, m, k;
vector<pii> adj[106];
vi par(106);
vi d(106, INF32);

void dijkstra(int u){
    for(int i = 0; i < par.size(); i++)
        par[i] = i;
    for(int i = 0; i < d.size(); i++)
        d[i] = INF32;
    vi vis(n+1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[u] = 0;
    pq.push({0, u});
    while(!pq.empty()){
        pii t = pq.top();
        pq.pop();
        if(vis[t.se]) continue;
        vis[t.se] = 1;
        for(auto it : adj[t.se]){
            int u = it.fi;
            int w = it.se;
            if(d[u] > d[t.se] + w){
                d[u] = d[t.se] + w;
                par[u] = t.se;
                pq.push({d[u], u});
            }
        }
    }
}

void print_path(int u, int v){
    vi path;
    int cnt = 2;
    path.pb(v);
    while(par[v] != u){
        path.pb(par[v]);
        v = par[v];
        cnt++;
    }
    path.pb(u);
    reverse(path.begin(), path.end());
    cout << cnt << " ";
    for(int x : path)
        cout << x << " ";
    cout << endl;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    while(k--){
        int tv; cin >> tv;
        int u, v; cin >> u >> v;
        if(u == v){
            if(tv == 0)
                cout << 0 << '\n';
            else
                cout << 1 << " " << u << '\n';
            continue;
        }
        dijkstra(u);
        if(tv == 0)
            cout << d[v] << endl;
        else
            print_path(u, v);
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

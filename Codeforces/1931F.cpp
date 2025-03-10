// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (int)(1e9+7)
#define INF32 ((1ull<<31)-1)
#define INF64 ((1ull<<63)-1)
#define bit(mask, i) ((mask>>i)&1)
 
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006
#define MASK64(x) (1LL << (x))
#define tuple64 tuple<ll, int, int>

int cnt = 1;

void dfs(int u, vector<int> adj[], vector<bool> &visited, vector<int> &topo){
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v])
            dfs(v, adj, visited, topo);
    topo[u] = cnt;
    cnt++;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<vi> a(k, vi (n));
    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            a[i][j]--;
        }

    vector<int> adj[n];
    for(int i = 0; i < k; i++)
        for(int j = 1; j < n-1; j++)
            adj[a[i][j]].pb(a[i][j+1]);

    vector<bool> visited(n, 0);
    vector<int> topo(n, -1);
    for(int i = 0; i < n; i++)
        if(topo[i] == -1)
            dfs(i, adj, visited, topo);
    for(int i = 0; i < k; i++)
        for(int j = 1; j < n-1; j++)
            if(topo[a[i][j]] < topo[a[i][j+1]]){
                cout << "NO" << '\n';
                return;
            }
    cout << "YES" << '\n';
}   
 
 
int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif    
    int t; cin >> t;
    while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
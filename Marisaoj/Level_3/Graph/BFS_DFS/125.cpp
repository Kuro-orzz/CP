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
int n, m, k, a[N];
vector<vector<int>> adj;
vector<int> d, vis;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                d[v] = d[u] + 1;
                vis[v] = 1;
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d.resize(n+1);
    vis.resize(n+1);
    bfs(n);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (d[a[i]] <= d[1]) ans++;
    }
    cout << ans;
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
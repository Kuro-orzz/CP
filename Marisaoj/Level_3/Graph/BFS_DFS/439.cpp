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

const int N = 1e3+6;
int n, m, k;
int p[N], vis[N];
multiset<int> ms;
vector<vector<int>> adj;
vector<pii> road;

int bfs(int i, int j) {
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    q.push({i, 0});
    q.push({j, 0});
    vis[i] = vis[j] = 1;
    int res = 0;
    while (!q.empty()) {
        auto [u, dist] = q.front(); q.pop();
        res += dist * ms.count(u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                q.push({v, dist + 1});
                vis[v] = 1;
            }
        }
    }
    return res;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        ms.insert(p[i]);
    }
    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        road.emplace_back(u, v);
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        auto [u, v] = road[i];
        ans = min(ans, bfs(u, v));
    }
    cout << ans;
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
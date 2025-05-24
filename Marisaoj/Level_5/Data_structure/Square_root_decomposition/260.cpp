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

const int N = 1e5+6;
int n, q;
ll val[N], lazy[N];
vector<vector<int>> adj, heavy;

void solve(){
    cin >> n >> q;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    size_t S = sqrt(n);
    heavy.resize(n+1);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (adj[v].size() > S)
                heavy[u].push_back(v);
        }
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, d; cin >> u >> d;
            if (adj[u].size() > S) lazy[u] += d;
            else {
                for (int v : adj[u]) val[v] += d;
            }
        } else if (type == 2) {
            int u; cin >> u;
            ll ans = val[u];
            for (int v : heavy[u]) ans += lazy[v];
            cout << ans << '\n';
        }
    }
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
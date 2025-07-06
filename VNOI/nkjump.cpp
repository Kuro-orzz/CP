/* 
    Author: Đỗ Tuấn Hưng (UETot)
    https://github.com/Kuro-orzz/Library
*/
#include <bits/stdc++.h>
using namespace std;

#define TASK "test"
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define pii pair<int, int>
#define fi first
#define se second

int n, a[1000];
map<int, vector<int>> adj;
map<int, int> vis, d;
stack<int> st;

void topo(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        topo(v);
    }
    st.push(u);
}

int cnt = 0;

void dfs(int u, int depth) {
    if (depth <= d[u]) return;
    d[u] = max(d[u], depth);
    cnt = max(cnt, depth);
    for (int v : adj[u]) {
        dfs(v, d[u] + 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    set<int> s(a, a+n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (s.count(a[i] + a[j])) {
                adj[a[i]].push_back(a[i] + a[j]);
                adj[a[j]].push_back(a[i] + a[j]);
            }
        }
    }
    for (int x : s) {
        if (!vis[x]) topo(x);
    }
    int ans = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (d[u]) continue;
        cnt = 0;
        dfs(u, 1);
        ans = max(ans, cnt);
    }
    cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

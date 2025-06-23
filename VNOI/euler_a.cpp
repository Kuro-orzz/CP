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

template <typename T>
struct Fenwick{
    int n;
    vector<T> fen;

    Fenwick(int _n): n(_n), fen(_n+1) {}

    void update(int pos, T val) {
        for (; pos <= n; pos += pos & -pos) {
            fen[pos] += val;
        }
    }

    T get(int pos) {
        T ans = 0;
        for (; pos > 0; pos -= pos & -pos) {
            ans += fen[pos];
        }
        return ans;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    void update_range(int l, int r, T val){
        update(l, val);
        update(r+1, -val);
    }

    void reset() {
        fill(all(fen), T(0));
    }
};

vector<int> EulerTour(vector<int> &st, vector<int> &en, 
                vector<vector<int>> &adj, int root = 0, int type = 0) {
    int n = adj.size();
    st.assign(n, 0);
    en.assign(n, 0);
    vector<int> tour;
    if (type == 0) tour.reserve(n);
    else if (type == 1) tour.reserve(2 * n);
    int pos = 0;
    function<void(int, int)> dfs = [&] (int u, int par) {
        tour.push_back(u);
        st[u] = ++pos;
        for (int v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);
        }
        if (type == 1) {
            tour.push_back(u);
            pos++;
        }
        en[u] = pos;
    };
    dfs(root, -1);
    return tour;
}

void solve() {
    int n, q; cin >> n >> q;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> st, en;
    vector<int> tour = EulerTour(st, en, adj, 1);
    Fenwick<ll> BIT((int)tour.size() + 1);
    for (int i = 1; i <= n; i++) BIT.update(st[i], a[i]);
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int u, x; cin >> u >> x;
            ll cur = BIT.get(st[u], st[u]);
            BIT.update(st[u], x-cur);
        } else if (type == 2) {
            int u; cin >> u;
            cout << BIT.get(st[u], en[u]) << '\n';
        }
    }
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

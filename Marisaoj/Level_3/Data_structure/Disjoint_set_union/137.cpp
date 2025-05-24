#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int N = 1e5+6;
int n, m, q;
vector<pii> edge, query;
unordered_set<int> s;

struct Dsu {
    vector<int> par, sz;

    Dsu(int n): par(n+1), sz(n+1, 1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if(v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

void solve(){
    cin >> n >> m >> q;
    edge.resize(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].fi >> edge[i].se;
    }
    query.resize(q+1);
    for (int i = 1; i <= q; i++) {
        cin >> query[i].fi >> query[i].se;
        s.insert(query[i].fi);
    }
    Dsu g(n);
    for (int i = 1; i <= m; i++) {
        if (!s.count(i)) g.merge(edge[i].fi, edge[i].se);
    }
    vector<int> ans;
    for (int i = q; i >= 1; i--) {
        auto [e, c] = query[i];
        ans.push_back(g.sz[g.find(c)]);
        g.merge(edge[e].fi, edge[e].se);
    }
    reverse(all(ans));
    for (int x : ans)
        cout << x << '\n';
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
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
int n, q;
vector<pii> a, query;
int mark[N];

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
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back({x, i});
    }
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        query.push_back({x, i});
    }
    sort(all(a));
    sort(all(query));
    int ptr = 0;
    int res = 0;
    vector<int> ans(q);
    Dsu g(n);
    for (int i = 0; i < q; i++) {
        int k = query[i].fi;
        while (ptr < n && a[ptr].fi <= k) {
            mark[a[ptr].se] = 1;
            if (!res) res = 1;
            if (a[ptr].se && mark[a[ptr].se-1]) {
                g.merge(a[ptr].se, a[ptr].se-1);
                res = max(res, g.sz[g.find(a[ptr].se)]);
            }
            if (a[ptr].se < n-1 && mark[a[ptr].se+1]) {
                g.merge(a[ptr].se, a[ptr].se+1);
                res = max(res, g.sz[g.find(a[ptr].se)]);
            }
            ptr++;
        }
        ans[query[i].se] = res;
    }
    for (int x : ans) cout << x << '\n';
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
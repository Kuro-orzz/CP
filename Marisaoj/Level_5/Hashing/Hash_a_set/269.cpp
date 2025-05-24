// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vector<ll> H;

struct DSU{
    vector<ll> par, value;
    ll s;
    DSU(int n): par(n+1), value(n+1), s(0){
        for(int i = 1; i < n+1; i++){
            par[i] = i;
            value[i] = H[i];
            s += value[i];
        }
    } 
    int find(int v){
        if(par[v] == v)
            return v;
        return par[v] = find(par[v]);
    }
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        s -= value[v]+value[u];
        value[v] ^= value[u];
        s += value[v]; 
        par[u] = v;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    H.resize(n+1);
    mt19937_64 rng(time(0));
    for(int i = 0; i < n+1; i++)
        H[i] = rng();
    DSU walk(n), subway(n);
    while(q--){
        int tv, u, v; cin >> tv >> u >> v;
        if(tv == 1)
            walk.merge(u, v);
        else
            subway.merge(u, v);
        if(walk.s == subway.s)
            cout << "YES\n";
        else
            cout << "NO\n";
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
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

struct dsu{
    int num = maxn;
    int Max = 1;
    int par[maxn], sz[maxn];
    void make_set(){
        for(int i = 0; i < maxn; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int v){
        if(v == par[v])
            return v;
        return par[v] = find(par[v]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(sz[a] < sz[b]) swap(sz[a], sz[b]);
            par[b] = a;
            sz[a] += sz[b];
            Max = max(Max, sz[a]);
            num--;
        }
    }
};

void solve(){
    int n, q; cin >> n >> q;
    dsu g;
    g.make_set();
    g.num = n;
    while(q--){
        int u, v; cin >> u >> v;
        g.Union(u, v);
        cout << g.num << " " << g.Max << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
    // cin.exceptions(cin.failbit);
    freopen("CLUSTER.INP", "r", stdin);
    freopen("CLUSTER.OUT", "w", stdout);
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

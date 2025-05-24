#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct dsu{
    vector<int> par, sz;
    dsu(int n): par(n), sz(n, 1){
        for(int i = 0; i < par.size(); i++)
            par[i] = i;
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
            if(sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve(){
    int n, q; cin >> n >> q;
    dsu g(n+1);
    while(q--){
        int type, u, v; cin >> type >> u >> v;
        if(type == 1)
            g.Union(u, v);
        else{
            if(g.find(u) == g.find(v))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
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
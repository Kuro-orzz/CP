#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define maxn 10006

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
    int park(int u){
        u = find(u);
        int v = find(par[u]);
        if(u == par.size()-1)
            par[u] = par[1];
        else
            par[u] = par[u+1];
        return v;
    }
};

void solve(){
    int n; cin >> n;
    dsu g(n+1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cout << g.park(x) << ' ';
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
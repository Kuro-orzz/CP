// #define _CRT_SECURE_NO_WARNINGS
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#include <bits/stdc++.h>
using namespace std;

#define filein() freopen("test.inp", "r", stdin);
#define fileout() freopen("test.out", "w", stdout);
#define fast() ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define ll long long
#define MOD (int)(1e9+7)
#define N (int)1e7
#define INF ((1ll<<31)-1)
#define bit(mask, i) ((mask>>i)&1)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 200006

int n, q, r[maxn], sz[maxn];//root

int get(int u){
    while(u != r[u])
        u = r[u];
    return u;
}

void check(int u, int v){
    u = get(u);
    v = get(v);
    if(u == v) cout << "YES" << endl;
    else cout << "NO" << endl;
}

void Union(int u, int v){
    u = get(u);
    v = get(v);
    if(u != v){
        if(sz[u] < sz[v])
            swap(u, v);
        r[v] = u;
        sz[u] += sz[v];
    }
}

void solve(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) r[i]=i, sz[i]=1;
    while(q--){
        string s; cin >> s;
        int u, v; cin >> u >> v;
        if(s == "union")
            Union(u, v);
        else
            check(u, v);
    }
}

int main(){
    fast();
    #ifndef ONLINE_JUDGE
    filein(); fileout();
    #endif    
    // int t; cin >> t;
    // while(t--)
        solve();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}
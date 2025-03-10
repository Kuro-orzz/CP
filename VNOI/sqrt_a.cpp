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
#define FOR(i, x, n) for(int i = x; i < n; i++)
#define REP(i, x, n) for(int i = x; i <= n; i++)

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define maxn 10006

int block_sz;
vector<int> a;
vector<ll> block;

void preprocess(vi &a, int n){
    block_sz = sqrt(n);
    block.resize(n/block_sz+2);
    int cnt = -1;
    for(int i = 0; i < n; i++){
        if(i % block_sz == 0)
            cnt++;
        block[cnt] += a[i];
    }
}

ll query(int l, int r){
    ll sum = 0;
    for(int i = l; i <= r;){
        if(i % block_sz == 0 && i+block_sz-1 <= r){
            sum += block[i/block_sz];
            i += block_sz;
        }
        else{
            sum += a[i];
            i++;
        }
    }
    return sum;
}

void update(int x, int val){
    block[x/block_sz] += val-a[x];
    a[x] = val;
}

void solve(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(a, n);
    while(q--){
        int tv; cin >> tv;
        int u, v; cin >> u >> v;
        if(tv == 1)
            update(u-1, v);
        else
            cout << query(u-1, v-1) << '\n';
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

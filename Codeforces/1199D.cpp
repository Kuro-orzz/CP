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
vector<int> block;

void preprocess(int n){
    block_sz = sqrt(n);
    block.resize(n/block_sz+2);
    int cnt = -1;
    for(int i = 0; i < n; i++){
        if(i % block_sz == 0)
            cnt++;
        block[cnt] = min(block[cnt], a[i]);
    }
}

void query(int k, int p, int x){
    if(k == 1){
        int bl = p/block_sz;
        for(int i = bl*block_sz; i < min((int)a.size(), bl*block_sz+block_sz); i++){
            if(i == p)
                a[i] = x;
            else
                a[i] = max(a[i], block[bl]);
        }
        block[bl] = 0;
        return;
    }
    for(int i = 0; i <= a.size(); i += block_sz)
        block[i/block_sz] = max(block[i/block_sz], x);
}

void solve(){
    int n; cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(n);
    int q; cin >> q;
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int p, x; cin >> p >> x;
            query(tv, p-1, x);
        }
        else{
            int x; cin >> x;
            query(tv, 0, x);
        }
    }
    for(int i = 0; i < a.size(); i++){
        a[i] = max(a[i], block[i/block_sz]);
    }
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
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
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
vector<ll> a;
vector<vector<ll>> block;

bool check(ll i, int k){
    if(i % k == 0)
        return true;
    while(i){
        if(i % 10 == k) return true;
        i /= 10;
    }
    return false;
}

void preprocess(int n){
    block_sz = sqrt(n);
    block.resize(block_sz+2, vector<ll>(10, 0));
    for(int i = 0; i < n; i++){
        for(int k = 1; k <= 9; k++){
            if(check(i+1, k))
                block[i/block_sz][k] += 2*a[i];
            else
                block[i/block_sz][k] += a[i];
        }
    }
}

void update(int i, int c){
    for(int k = 1; k <= 9; k++){
        if(check(i, k))
            block[(i-1)/block_sz][k] += 2*(c-a[i-1]);
        else
            block[(i-1)/block_sz][k] += c-a[i-1];
    }
    a[i-1] = c;
}

ll segment(int l, int r, int k){
    ll sum = 0;
    for(int i = l; i <= r;){
        if(i % block_sz == 0 && i+block_sz-1 <= r){
            sum += block[i/block_sz][k];
            i += block_sz;
        }
        else{
            if(check(i+1, k))
                sum += 2*a[i];
            else
                sum += a[i];
            i++;
        }
    }
    return sum;
}

void solve(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(n);
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int i, c; cin >> i >> c;
            update(i, c);
        }
        else{
            int l, r, k; cin >> l >> r >> k;
            cout << segment(l-1, r-1, k) << '\n';
        }
    }
}

void sinh(){
    srand(time(NULL));
    int n = rand() % 100;
    int q = rand() % 100;
    cout << n << " " << q << '\n';
    for(int i = 0; i < n; i++)
        cout << rand() % (int)(1e9) << " ";
    for(int i = 0; i < q; i++){
        int tv = rand() % 2+1;
        cout << tv << " ";
        if(tv == 1){
            cout << rand() % n+1 << " ";
            cout << rand() % (int)1e9 << '\n';
        }
        else{
            int l = rand() % (n-1)+1;
            int r = rand() % (n-l)+l;
            int k = rand() % 9+1;
            cout << l << " " << r << " " << k << '\n';
        }
    }

}

void trau(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(q--){
        int tv; cin >> tv;
        if(tv == 1){
            int i, c; cin >> i >> c;
            a[i-1] = c;
        }
        else{
            int l, r, k; cin >> l >> r >> k;
            ll ans = 0;
            for(int i = l-1; i <= r-1; i++)
                if(check(i+1, k))
                    ans += a[i]*2;
                else
                    ans += a[i];
            cout << ans << '\n';
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
    // sinh();
        solve();
        // trau();
    cerr << "\nTime run: " << 1000 * clock() / CLOCKS_PER_SEC << "ms" << '\n';
    return 0;
}

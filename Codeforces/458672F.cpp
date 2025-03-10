#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(),(x).end()

#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

vi a, block;
int block_sz;

void preprocess(int n){
    block_sz = sqrt(n);
    block.resize(block_sz+2, 0);
    for(int i = 0; i < n; i++)
        block[i/block_sz] += a[i];
}

int query(int k){
    int cnt = 0;
    int i = 0;
    while(cnt + block[i/block_sz] < k){
        cnt += block[i/block_sz];
        i += block_sz;
    }
    while(cnt+a[i] < k){
        cnt += a[i];
        i++;
    }
    return i;
}

void update(int x){
    if(a[x] == 1)
        block[x/block_sz]--;
    else
        block[x/block_sz]++;
    a[x] ^= 1;
}

void solve(){
    int n, q; cin >> n >> q;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    preprocess(n);
    while(q--){
        int tv, x; cin >> tv >> x;
        if(tv == 1)
            update(x-1);
        else
            cout << query(x)+1 << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(NULL);
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
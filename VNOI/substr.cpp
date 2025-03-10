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
#define maxn 1000006
#define tuple64 tuple<ll, int, int>

const int base = 90;
ll POW[maxn], hashA[maxn];


int getHash(int i, int j){
    return (hashA[j] - hashA[i-1] * POW[j-i+1] + MOD*MOD) % MOD;
}

void solve(){ 
    string a, b; cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = " " + a;
    b = " " + b;
    POW[0] = 1;
    for(int i = 1; i <= n; i++)
        POW[i] = (POW[i-1]*base) % MOD;

    hashA[0] = 0;
    for(int i = 1; i <= n; i++)
        hashA[i] = (hashA[i-1] * base + a[i] - 'a' + 1) % MOD;

    ll hashB = 0;
    for(int i = 1; i <= m; i++)
        hashB = (hashB * base + b[i] - 'a' + 1) % MOD;

    for(int i = 1; i <= n-m+1; i++)
        if(hashB == getHash(i, i+m-1))
            cout << i << " ";

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
